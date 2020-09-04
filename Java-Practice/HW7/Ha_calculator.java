package HA_homework;


public class Ha_calculator {

	public static void main(String[] args) {
		int key = Integer.parseInt(args[0]);
		System.out.println("���ڸ� �Է��ϼ���. "); 
	
		
		MultiThread[] mt = new MultiThread[key]; //�Է� ���� ���ڸ�ŭ ��ü �迭�� ���۷��� ������ �����Ѵ�.
		for(int i=0;i<key;i++) {
			mt[i]=new MultiThread(); //��ü ����
			mt[i].store(i+1); // 1,2,3,4 ... key ���� ������� ���� �����Ų��.
			mt[i].start();
		}
		try {
			for(int i=0;i<key;i++) {
				mt[i].join(); //�ٸ� �������� ���Ḧ ��ٸ���.
			}
		}
		catch(InterruptedException e) {
			Thread.currentThread().interrupt(); //�����带 �����ϱ� ���� ��Ŀ����
		}
		System.out.println("total is "+ MultiThread.sum); //���� total ���� ����Ѵ�.

	}
}

class MultiThread extends Thread{
	static int sum=0; //�������� ����
	fac_calculator c;
	int num;
	MultiThread(){
		c =new fac_calculator(); //�����ڿ��� fac_calculator ��ü ����
	}
	public void store(int n) { //������ factorial ���� ���ϱ� ���� ���ڸ� �����Ų��.
		num = n;
	}
	public void run() {
		try {
			int result = c.factorial(num);
			sum += result; //static ���� sum�� ��� ���� ���ؼ� �����Ѵ�.
			System.out.println(num+"! ="+ result); //������ factorial�� ���� ����Ѵ�.
		}catch(Exception e) {
			e.printStackTrace(); //���� �޼����� �߻� �ٿ����� ã�� �ܰ躰�� ���� ���
			System.out.println("���� �߻�!!");
		}
	}
}
class fac_calculator{
	public synchronized int factorial(int num) { //�Ӱ� ������ �����Ͽ� ���� �����͸� ����ϰ� �ִ� �ش� �����带 �����ϰ�,������ ��������� �����Ϳ� ������ �� ������ ���� ���� �� 
	int result =0;
		if(num == 1) {
		result = 1;
	}
		else {
			result = num * factorial(num-1);
		}
		return result; //factorial�� ���� ����
	}
}
