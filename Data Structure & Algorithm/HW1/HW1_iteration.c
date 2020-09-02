#include<stdio.h>
#include<time.h>	//�ð� ������ ���� ���̺귯��

int fib(int num);
int fib2(int num);
int main() {
	clock_t start, end;
	float result;
	start = clock();  //�ð� ���� ����
	int seriesSize;
	printf("Input numbers : ");
	scanf("%d", &seriesSize);	 //���ڸ� �Է¹޴´�.

	printf("Print a Fibonacci series (Iteration). \n");

	for (int looper = 0; looper < seriesSize; looper++) {
		if (looper % 5)			// ���� 5���� ��� ���� �ٲپ���.
			printf(", %4d", fib(looper));		// %4d�� �̿��Ͽ� ���ڳ��� ����־���.
		else
			printf("\n%4d", fib(looper));
	}
	printf("\n");
	end = clock();	//�ð� ���� ��
	result = (float)(end - start) / CLOCKS_PER_SEC;
	printf("�ҿ�� �ð� : %f", result);
	return 0;

}
int fib(int num) {
	int result;
	if (num == 0 || num == 1) {
		return num;
	}
	else {
		result = fib2(num);		//�Ǻ���ġ ���� ��� �Լ� ȣ��
	}
	return result;
}
int fib2(int num) {			//Iteration�� �̿��� �Ǻ���ġ ���� ���
	int a = 0;
	int b = 1;
	int temp;
	for (int i = 0; i < num - 1; i++) {
		temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}