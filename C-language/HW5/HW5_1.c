#include<stdio.h>
int main()
{
	char name[6], newname[6];
	int key, i;

	printf("���ڿ��� �Է��ϼ���\n");
	scanf("%s", &name);   //���ڿ� �Է¹ޱ�
	do {
		printf("key���� �Է��ϼ���\n");
		scanf("%d", &key);   //key�� �Է¹ޱ�
	} while (key < 1 || key>26);   //key������ 1���� 26������ ���� �Է����� ������ �ٽ� �ݺ��Ѵ�.
	for (i = 0; i < 5; i++)
	{
		newname[i] = name[i] + key; //������ ���ڿ���  key���� ���Ѵ�.
	}
	for (i = 0; i < 5; i++)
	{
		if (newname[i] > 122) //���ĺ� z�� ���ڸ� �������� �ٽ� a���� ��ȯ�ϵ��� �Ѵ�. (ASCII �ڵ� ����)
		{
			newname[i] -= 26;
		}
	}
	printf("�⺻ ���ڿ� %s\n��ȣȭ �� ���ڿ� ", name);
	for (i = 0; i < 5; i++) //��ȣȭ �� ���ڿ� ���
	{
		printf("%c", newname[i]);
	}
	printf("\n");
	do {
		printf("key���� �Է��ϼ���\n");
		scanf("%d", &key); //key�� �Է¹ޱ�
	} while (key < 1 || key>26); //key������ 1���� 26������ ���� �Է����� ������ �ٽ� �ݺ��Ѵ�.
	for (i = 0; i < 5; i++) // ��ȣȭ �� ���ڿ����� key ���� ����.
	{
		name[i] = newname[i] - key;
	}
	for (i = 0; i < 5; i++)
	{
		if (name[i] < 97) //���ĺ� a���� ���ڸ� �� ��� �ݴ�� z���� ��ȯ�ϵ��� �Ѵ�. (ASCII �ڵ� ����)
		{
			name[i] += 26;
		}
	}
	printf("��ȣȭ �� ���ڿ� ");
	for (i = 0; i < 5; i++) //��ȣȭ �� ���ڿ��� ����Ѵ�.
	{
		printf("%c", name[i]);
	}
	printf("\n��ȣȭ �� ���ڿ� ");
	for (i = 0; i < 5; i++) //��ȣȭ �� ���ڿ��� ����Ѵ�.
	{
		printf("%c", newname[i]);
	}

	for (i = 0; i < 27; i++) // 1�� 26������ ��� ���ڵ��� �̿��ؼ� ��ȣȭ�� ���� �Ѵ�.
	{
		printf("\nkey �� %d ��ȣȭ �� ���ڿ� ", i);
		for (int j = 0; j < 5; j++)
		{
			if (newname[j] - i < 97) //���ĺ� a���� ���ڸ� �� ��� �ݴ�� z���� ��ȯ�ϵ��� �Ѵ�.
			{
				printf("%c", newname[j] - i + 26);
			}
			else
			{
				printf("%c", newname[j] - i);
			}
		}
	}
}