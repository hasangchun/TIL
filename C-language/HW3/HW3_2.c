#include<stdio.h>
int main()
{
	int num;    //���� ����
	printf("Num :");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)  //num��ŭ�� �� �����
	{
		if (i == 0 || i == num - 1)  //ù°�� �Ǵ� �������ٿ� ���� ���ǽ�
		{
			for (int j = 0; j < num; j++)
			{
				printf("��");
			}
			printf("\n");  //�ٹٲ�
		}
		else if (i % 2 == 0)  //�տ� if������ �ѹ� �ɷ����� �� ���� i�� ¦����� �̶�� ���ǽ�
		{
			for (int j = 0; j < num; j++) {
				if (j == 0 || j == num - 1)   //�� ùĭ �Ǵ� �� ������ ĭ�� ���� ���ǽ�
				{
					printf("��");
				}
				else if (i + j == num - 1 || i == j) //�밢���̶��
				{
					printf("��");
				}
				else if (j % 2 == 0) //�տ� if������ �ɷ����� ���� ������ �� ¦�����
				{
					printf("��");
				}
				else {
					printf("  ");
				}
			} printf("\n");
		}
		else     //�տ� if���鿡�� �ɷ����� ������
		{
			for (int j = 0; j < num; j++)
			{
				if (j == 0 || j == num - 1)
				{
					printf("��");
				}
				else {
					printf("  ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}