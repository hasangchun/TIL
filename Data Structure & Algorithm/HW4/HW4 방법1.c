#include <stdio.h>
#include <math.h> //abs ������ ����ϱ� ���� �������
#define MAXSIZE 8 //�ִ� ��
#define true 1 //���� ���� true, false�� 1, 0 ���� ����
#define false 0
typedef int boolean;  //�������� ���̱� ���� int �ڷ����� boolean �ڷ������� ���ڴ�.
int count = 0;// ��������
int matrix[MAXSIZE];  //��������

boolean check(int num) { //��ġ �������� �˻�
	int k = 0;
	boolean flag = true;
	while (k < num && flag)
	{	//���� ���̰ų� �밢���̸� ��ġ ���Ѵ�.
		if (matrix[num] == matrix[k] || abs(matrix[num] - matrix[k]) == num - k) {
			flag = false;
		}
		k++;
	}
	return flag;
}
void put_queen(int num) {
	if (check(num)) {
		if (num == (MAXSIZE-1) {  //���� �ϼ� �Ǿ����ϱ� count 1����
			count++;
		}
		else {
			for (int j = 0; j < MAXSIZE; j++) {
				matrix[num + 1] = j;  //�ݺ����� ���� �� ���� �ϳ��� ��ġ, �迭�� �ε����� ���̰� ���� ���̴�.
				put_queen(num + 1); // ��� �Լ��� num+1�� ���� ������ �Ʒ��� ������ ��������.
			}
		}
	}
}
int main(void) {
	for (int i = 0; i < MAXSIZE; i++)
	{
		matrix[0] = i;
		put_queen(0);
	}
	printf("\n8-queens problem solution : %d��\n", count);
	return 0;
}