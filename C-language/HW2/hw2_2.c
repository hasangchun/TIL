#include<stdio.h>
int main()
{
	int num, col, row; //��������
	printf("Number ? : ");
	scanf("%d", &num); //  num�� �Է¹ޱ�

	for (row = 0; row < num; row++)    //���� �ݺ��ϴ� �ݺ���
	{

		for (col = num; col > row + 1; col--)  //���� �ݺ��ϴ� �ݺ���
		{
			printf("��");
		}
		for (col = 0; col <= row; col++)  //���� �ݺ��ϴ� �ݺ���
		{
			printf("��");
		}

		printf("\n");  //�ٹٲٱ�
	}
	return 0;
}