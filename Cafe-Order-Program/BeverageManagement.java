package ServerProgram;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class BeverageManagement implements PublicConstants {
	private String url;
	private String username;
	private String password;
	private String query;
	private Statement stmt;
	private Connection conn;
	Scanner sc;

	// INIT
	BeverageManagement() {
		this.sc = new Scanner(System.in);
		this.url = "jdbc:oracle:thin:@localhost:1521:orcl";
		this.username = null;
		this.password = null;
		this.conn = null;
		this.query = null;
		this.stmt = null;
	}

	// CONNECT
	public boolean connect() {
		System.out.print(DB_LOGIN_ID_MSG);
		this.username = sc.next();
		System.out.print(DB_LOGIN_PASSWD_MSG);
		this.password = sc.next();

		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			conn = DriverManager.getConnection(this.url, this.username, this.password);
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		if (conn == null) {
			System.out.println(DB_NOT_CONNECT);
			return false;
		} else {
			System.out.println(DB_CONNECT);
			return true;
		}

	}

	// 0�� �ֹ� ���� ���
	public String[] printOrder() {
		String[] menuCode = new String[30]; // �����Ӱ� �ֹ����� ���� 30��
		int[] beverageNum = new int[30];
		int orderMenuNum = 0;
		int menuNum = 0;
		String sendMSG[] = new String[20];
		try {
			this.query = "SELECT * FROM ORDER_TABLE";
			this.stmt = this.conn.createStatement();
			ResultSet rs = this.stmt.executeQuery(this.query);
			while (rs.next()) {
				menuCode[orderMenuNum] = rs.getString("MENU_CODE");
				beverageNum[orderMenuNum++] = rs.getInt("BEVERAGE_NUM");
			}
			this.query = "SELECT * FROM BEVERAGE_COMPONENT_TABLE";
			rs = this.stmt.executeQuery(this.query);
			while (rs.next()) {
				for (int x = 0; x < orderMenuNum; x++) {
					if (rs.getString("MENU_CODE").equals(menuCode[x])) {
						for (int y = 0; y < beverageNum[x]; y++) {
							sendMSG[menuNum++] = rs.getString("BEVERAGE_NAME") + TAP + rs.getString("COMPONENT_CHA1")
									+ TAP + rs.getString("COMPONENT_CHA2");
						}
					}
				}
			}

		} catch (SQLException e) {
			e.printStackTrace();
		}
		return sendMSG;

	}

	// 1�� NEW ORDER ���ο� �ֹ� DB�� �߰��ϴ� ����
	public String insertDB(Beverage bev) {
		int updateNum = 0;
		int changeNum = 0;
		String msg;
		boolean change = false;
		try {
			this.stmt = this.conn.createStatement();
			this.query = "SELECT * FROM ORDER_TABLE";
			ResultSet rs = this.stmt.executeQuery(this.query);
			while (rs.next()) {
				if (rs.getInt("BEVERAGE_NUM") > 0 && rs.getString("BEVERAGE_NAME").equals(bev.getBerverageName())
						&& rs.getString("BEVERAGE_TEMPERATURE").equals(bev.getTemperature())) {
					changeNum = rs.getInt("BEVERAGE_NUM") + bev.getNum();
				}
			}
			if (changeNum > 0) {
				this.query = "UPDATE ORDER_TABLE SET BEVERAGE_NUM = " + changeNum + " WHERE BEVERAGE_NAME = '"
						+ bev.getBerverageName() + "'";
				updateNum = this.stmt.executeUpdate(this.query);
				msg = updateNum + "���� ������Ʈ �Ǿ����ϴ�.";
				return msg;
			} else {
				this.query = "SELECT * FROM BEVERAGE_COMPONENT_TABLE";
				rs = this.stmt.executeQuery(this.query);
				while (rs.next()) {
					if (rs.getString("MENU_CODE").equals(bev.getBerverageName() + "_" + bev.getTemperature())) {
						change = true;
						break;
					}
				}

				if (change) {
					this.query = "INSERT INTO ORDER_TABLE VALUES" + SQL_OPEN + bev.getBerverageName() + "_"
							+ bev.getTemperature() + SQL_COMMA + bev.getBerverageName() + SQL_COMMA
							+ bev.getTemperature() + SQL_INT_COM + bev.getNum() + SQL_INT_CLOSE;
					updateNum = this.stmt.executeUpdate(query);
				}

				if (!change) {
					msg = "�޴��� �����ϴ�. �ٸ� ���Ḧ �ֹ��ϼ���.";
					return msg;
				}
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		msg = updateNum + "���� ������Ʈ �Ǿ����ϴ�.";
		return msg;
	}

	// �ֹ� ������ �ִ��� Ȯ�� �ϴ� �Լ� , �޴��ǿ� �ִ��� Ȯ�� �ϴ� �Լ� (parameter �ٸ��� ����)
	private boolean checkOrder(String deleteName, String table, String memo) {
		String[] menuCode = new String[30];
		int i = 0;
		try {
			this.query = "SELECT * FROM " + table;
			this.stmt = this.conn.createStatement();
			ResultSet rs = this.stmt.executeQuery(this.query);
			while (rs.next()) {
				menuCode[i++] = rs.getString("MENU_CODE");
			}
			for (int j = 0; j < i; j++) {
				if (menuCode[j].equals(deleteName)) {
					return true;
				}
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}

	// db���� beverage_component_table �о���� �Լ�
	public String[] AdminReadMenu() {
		String[] menuCode = new String[30];
		int i = 0;
		try {
			this.query = "SELECT * FROM BEVERAGE_COMPONENT_TABLE";
			this.stmt = this.conn.createStatement();
			ResultSet rs = this.stmt.executeQuery(this.query);
			while (rs.next()) {
				menuCode[i++] = rs.getString("MENU_CODE");
			}

		} catch (SQLException e) {
			e.printStackTrace();
		}
		return menuCode;
	}

	// db���� order_table �������� �Լ�
	private String[] readMenu() {
		String[] menuCode = new String[30];
		int i = 0;
		try {
			this.query = "SELECT * FROM ORDER_TABLE";
			this.stmt = this.conn.createStatement();
			ResultSet rs = this.stmt.executeQuery(this.query);
			while (rs.next()) {
				menuCode[i++] = rs.getString("MENU_CODE");
			}
			return menuCode;
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}

	// 2�� �ֹ� ����
	public String deleteOrder(String deleteName) {
		int updateNum = 0;
		if (!checkOrder(deleteName, "ORDER_TABLE", "�ֹ�����"))
			return "*** �ֹ������� �����ϴ�. ***";
		this.query = "DELETE ORDER_TABLE WHERE MENU_CODE = '" + deleteName + "'";
		try {
			this.stmt = this.conn.createStatement();
			updateNum = this.stmt.executeUpdate(query);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return updateNum + "���� ���� ������Ʈ �Ǿ����ϴ�.";
	}

	// ������ �α��� �ϱ�

	private boolean adminLogin(String adminId, String passwd) {
		this.query = "SELECT * FROM ADMIN_LIST";
		try {
			this.stmt = this.conn.createStatement();
			ResultSet rs = this.stmt.executeQuery(this.query);
			while (rs.next()) {
				if (rs.getString("ADMIN_ID").equals(adminId) && rs.getString("PASSWD").equals(passwd))
					return true;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return false;
	}

	// 3��
	public String onlyManager(String adminId, String passwd) {
		boolean loginSuccess = adminLogin(adminId, passwd);
		if (!loginSuccess) {
			return ADMIN_LOGIN_FAIL_MSG;
		}
		return ONLY_MANAGER_UI_MSG;
	}

	// �޴� �����ϱ�

	public String menuDelete(String deleteName) {
		int updateNum = 0;
		String msg = null;
		if (!checkOrder(deleteName, "BEVERAGE_COMPONENT_TABLE", "�޴�")) {
			return "***�޴��� �����ϴ�.***";
		}
		this.query = "DELETE BEVERAGE_COMPONENT_TABLE WHERE MENU_CODE = '" + deleteName + "'";
		try {
			this.stmt = this.conn.createStatement();
			updateNum = this.stmt.executeUpdate(this.query);
			if (updateNum == 1) {
				msg = MENU_DELETE_CONFIRM_MSG + "\n";
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		msg += updateNum + "���� ���� ������Ʈ �Ǿ����ϴ�.";
		return msg;
	}

	// ������ �޴� �߰� ���� �Լ�
	private boolean isMenu(String menu_code) {
		try {
			this.query = "SELECT * FROM BEVERAGE_COMPONENT_TABLE";
			this.stmt = this.conn.createStatement();
			ResultSet rs = stmt.executeQuery(query);
			while (rs.next()) {
				if (rs.getString("MENU_CODE").equals(menu_code))
					return false;
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return true;
	}

	// ������ �������� �Ÿ޴� �߰��ϱ�
	public String newMenuRegister(Beverage bev) {
		if (!isMenu(bev.getBerverageName() + "_" + bev.getTemperature())) {
			return "������ �޴��� �̹� �ֽ��ϴ�.";
		}
		return insertNewMenuDB(bev) + "���� ���� ������Ʈ �Ǿ����ϴ�.";
	}

	// �ֹ� ��ü �����ϱ�

	public String deleteAll(String msg) {
		int updateNum = 0;
		String message = null;
		if (msg.equals("Y")) {
			String[] menuCode = readMenu();
			for (int num = 0; menuCode[num] != null; num++) {
				this.query = "DELETE ORDER_TABLE WHERE MENU_CODE ='" + menuCode[num] + "'";
				try {
					this.stmt = this.conn.createStatement();
					updateNum = this.stmt.executeUpdate(query);

				} catch (SQLException e) {
					e.printStackTrace();
				}
			}
			if (updateNum == 1) {
				message = DELETE_ALL_ORDER_CONFIRM_MSG + "\n";
			}
			message += updateNum + "���� ���� ������Ʈ �Ǿ����ϴ�.";
			return message;
		} 
		else if(msg.equals("N")) {
			return NOT_DELETE_ALL_ORDER_MSG;
		}
		else {
			return NOT_DELETE_ALL_ORDER_MSG2;
		}
	}

	// db�� �Ÿ޴� �߰��ϱ�
	private int insertNewMenuDB(Beverage bev) {
		int updateNum = 0;
		try {
			this.stmt = this.conn.createStatement();
			this.query = "INSERT INTO BEVERAGE_COMPONENT_TABLE VALUES" + SQL_OPEN + bev.getBerverageName() + "_"
					+ bev.getTemperature() + SQL_COMMA + bev.getBerverageName() + "(" + bev.getTemperature() + ")"
					+ SQL_COMMA + bev.getRecipe1() + SQL_COMMA + bev.getRecipe2() + SQL_CLOSE;
			updateNum = this.stmt.executeUpdate(query);
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return updateNum;
	}

}
