#include<stdio.h>
#include<time.h>	//�ð� ������ ���� ���̺귯��
int fib(int num);
int main() {
	clock_t start, end;
	float result;
	start = clock();	//�ð� ���� ����
	int seriesSize;
	printf("Input numbers : ");
	scanf("%d", &seriesSize);  //���ڸ� �Է¹޴´�.

	printf("Print a Fibonacci series (Recursion). \n");

	for (int looper = 0; looper < seriesSize; looper++) {
		if (looper % 5)  // ���� 5���� ��� ���� �ٲپ���.
			printf(", %4d", fib(looper));  // %4d�� �̿��Ͽ� ���ڳ��� ����־���.
		else
			printf("\n%4d", fib(looper));
	}
	printf("\n");
	end = clock();		//�ð� ���� ��
	result = (float)(end - start) / CLOCKS_PER_SEC;
	printf("�ҿ�� �ð� : %f", result);	// �ҿ�� �ð� ���
	return 0;

}
int fib(int num) {			//��͸� �̿��� �Ǻ���ġ ���� ���
	if (num == 0 || num == 1) {
		return num;
	}
	return(fib(num - 1) + fib(num - 2));
}