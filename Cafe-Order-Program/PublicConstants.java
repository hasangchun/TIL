package ServerProgram;

public interface PublicConstants {
	public final static int SERVER_PORT = 9999;
	public final static String CONNECTING_MSG = "������ ��ٸ��� �ֽ��ϴ�.....";
	public final static String CONNECTED_MSG = "����Ǿ����ϴ�.";
	public static final String[] MENUS = { "## 0. �ֹ� ���� ���\n", "## 1. �ֹ� �ϱ�\n", "## 2. �ֹ� ���� ����\n",
			"## 3. ������ ���� ���α׷�\n", "## 4. ���α׷� ����\n", ">> Input : " };
	public final static String PROGRAM_END_MSG = "���α׷��� �����մϴ�.";
	public static final int MENU_NUM = 6;
	public static final int ORDER_LIST = 0;
	public static final int NEW_ORDER = 1;
	public static final int NEW_MENU_ADD = 1;
	public static final int DELETE_ORDER = 2;
	public static final int DELETE_MENU = 2;
	public static final int ALL_DELETE_ORDER = 3;
	public static final int ONLY_MANAGER = 3;
	public static final int EXIT = 4;
	public static final String TITLE = "\n\t### CafeOrder Management Program v1.1 ###\n";
	public static final String INT_MISMATCH_EXCEPT_MSG = "�߸��Է��߽��ϴ�!! ������ �ٽ� �Է����ּ���.";
	public static final String FATAL_ELSE_MSG = "�߻��ϸ� �� �Ǵ� else�� �߻��߽��ϴ�!!";
	public static final String NO_EXIST_BEVERAGE_MSG = "�ֹ��Ͻ� �޴��� �����ϴ�!!";
	public static final String ADMIN_LOGIN_ID_MSG = "������ ������ �ʿ��մϴ�.\n>> ADMIN ID : ";
	public static final String ADMIN_LOGIN_PASSWD_MSG = ">> ADMIN PASSWORD : ";
	public static final String ADMIN_LOGIN_FAIL_MSG = "������ ���� ���ٿ� �����ϼ̽��ϴ�.";
	public static final String DB_NOT_CONNECT = "�����ͺ��̽��� ������ ���� �ʾҽ��ϴ�\n���α׷��� ����˴ϴ�.";
	public static final String DB_CONNECT = "�����ͺ��̽��� ���� �Ǿ����ϴ�!!";
	public static final String TAP = "\t";
	public static final String SQL_COMMA = "','";
	public static final String SQL_INT_COMMA = ",";
	public static final String SQL_OPEN = "('";
	public static final String SQL_INT_COM = "',";
	public static final String SQL_INT_CLOSE = ")";
	public static final String SQL_CLOSE = "')";
	public static final String NOT_DELETE_ALL_ORDER_MSG = "�ֹ� ������ ��� ���� ���� �ʾҽ��ϴ�.";
	public static final String NOT_DELETE_ALL_ORDER_MSG2 = "��Ȯ�� �Է� ���� �ʾҽ��ϴ�!!";
	public static final String DELETE_ALL_ORDER_MSG = "��ü �ֹ� ������ �����Ͻðڽ��ϱ�?(Y,N)\nInput>> ";
	public static final String DELETE_ALL_ORDER_CONFIRM_MSG = "��ü �ֹ� ������ �����߽��ϴ�.";
	public static final String ONLY_MANAGER_UI_MSG = "1.�� �޴� �߰�\n2.�޴� ����\n3.�ֹ� ���� ��ü ����\nInput >> ";
	public static final String MENU_REGISTER_NAME = "�޴� �̸�?\n";
	public static final String MENU_REGISTER_TEMPERATURE = "�µ�(HOT,ICE)?\n";
	public static final String MENU_REGISTER_RECIPE1 = "������1(ex.�����200ML)?\n";
	public static final String MENU_REGISTER_RECIPE2 = "������2(ex.�ڸ�1)?\n";
	public static final String MENU_DELETE_MSG = "� �޴��� �����Ͻðڽ��ϱ�?(ex.�Ƹ޸�ī��_HOT)";
	public static final String MENU_DELETE_CONFIRM_MSG = "�޴��� �����߽��ϴ�.";
	public static final String DB_LOGIN_ID_MSG = "ORACLE ID : ";
	public static final String DB_LOGIN_PASSWD_MSG = "ORACLE PASSWD : ";

}
