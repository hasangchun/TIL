import java.util.Scanner;


public class Add {
	public Add() {
	}
private int a,b;
void setValue(int a, int b) {
	this.a=a;
	this.b=b;
}
int calculate() {
	return a+b;
}
}
public class Sub {
	public Sub() {
	}
private int a,b;
void setValue(int a, int b) {
	this.a=a;
	this.b=b;
}
int calculate() {
	return a-b;
}
}
public class Mul {
	public Mul() {
	}
private int a,b;
void setValue(int a, int b) {
	this.a=a;
	this.b=b;
}
int calculate() {
	return a*b;
}
}
public class Div {
	public Div() {
	}
private int a,b;
void setValue(int a, int b) {
	this.a=a;
	this.b=b;
}
int calculate() {
	if(b!=0) {return a/b;}
	else return 0;
}
}

public class Homework3 {

	public static void main(String[] args) {
	int x, y;
	Scanner scanner = new Scanner(System.in);
	while(true) {
	System.out.print("�� ������ �����ڸ� �Է��Ͻÿ�>>");
	x= scanner.nextInt();
	y = scanner.nextInt();
	char key = scanner.next().charAt(0);
	switch(key) {
	case '+':{
		Add add = new Add();
		add.setValue(x, y);
		System.out.println(add.calculate());
		break;
	}
	case '-':{
		Sub sub =new Sub();
		sub.setValue(x,y);
		System.out.println(sub.calculate());
		break;
	}
	case '*':{
		Mul mul =new Mul();
		mul.setValue(x,y);
		System.out.println(mul.calculate());
		break;
	}
	case '/':{
		Div div =new Div();
		div.setValue(x,y);
		if(div.calculate()!=0) {
		System.out.println(div.calculate());
		break;}
		else  {System.out.println("�ٽ� �Է��ϼ���!");
		continue;}
	}
	default: {System.out.println("�����ڰ� �����ϴ�.");
	continue;}
	}
	break;
	}
	}
}
