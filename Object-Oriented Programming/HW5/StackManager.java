package HA_homework;
import java.util.Vector;

interface IStack<T> {
T pop();
boolean push(T ob);
}

class Mystack<T> implements IStack<T>{
	Vector<T> v = new Vector<T>(10);
	public T pop() { 				// �� �������� �ִ� ���� �ϳ��� �������ִ� �޼ҵ�
		int num = v.size();
		if(num == 0) {
			return null;
		}
		else { 
			return v.remove(num-1); //�������ְ� remove �޼ҵ带 ���� �� ����
		}
	}
	public boolean push(T ob) { //���ο� ���� �־��ִ� �޼ҵ�
		v.add(ob);
		return true;
	}
}
public class StackManager {

	public static void main(String[] args) {
		IStack<Integer> Stack = new Mystack<Integer>();   //Mystack��ü ����
	      for(int i=0; i<10; i++) {                  //0���� 9���� ���� �־��ִ� �ݺ���
	         Stack.push(i);
	      }
	      while(true) {                           //���̻� ���� ���������� �ݺ�
	         Integer n = Stack.pop();   
	         if(n==null) {
	            break;
	         }
	         System.out.print(n+" ");               //�� ���
	      } 

	}

}
