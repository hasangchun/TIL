#include<stdio.h>
int main()
{
	int num;
	printf("Num :");
	scanf("%d", &num);
	for (int i = 0; i < num; i++) // num���� �� �����
	{
		if (i == 0 || i == num - 1) //�� ù°�� �Ǵ� �� �������ٿ� ���� ���ǽ�
		{
			for (int j = 0; j < num; j++)
			{
				printf("��");
			}
			printf("\n");  //�ٹٲ�
		}
		else {   //�տ� if������ �ѹ� �ɷ����� �� �� ������
			for (int j = 0; j < num; j++)
			{
				if (j == 0 || j == num - 1) // �ǿ��� �Ǵ� �� �������̶��
				{
					printf("��");
				}
				else {
					printf("  ");
				}
			}
			printf("\n"); //�ٹٲ�
		}
	}
	return 0;
}