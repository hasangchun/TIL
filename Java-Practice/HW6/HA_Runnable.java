package HA_homework;
import java.util.Scanner; //ScannerŬ������ ����ϱ� ���� import

public class HA_Runnable {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); //�Է¹ޱ� ���� Scanner Ŭ������ scanner ��ü ����
		System.out.print("�ƹ� Ű�� �Է�>> ");
	    scanner.next();  //scanner.nextLine() ���� �ϸ� ���ڿ��� �Է����� �ʰ� ���͸� ������ �Ѿ�� �����̴�.
	    Thread th = new Thread(new TimerRunnable());
		th.start();
	}
}

class TimerRunnable implements Runnable {
	int n =1;
	public void run() {
	    System.out.println("������ ���� ����");
		for(int i =0;i<10;i++) { //1���� 10���� ����ϱ� ���� �ݺ���
		System.out.print(n+ " ");
		n++;
		}
		System.out.println();
		System.out.println("������ ����");
	}
}
