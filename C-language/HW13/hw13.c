#include<stdio.h>
int main()
{
	char str1[30]; //�迭 ����
	FILE * rp = fopen("Hasangcheon.txt", "rt"); //������ �б� ���� ����. 
	if (rp == NULL) //���� ���⸦ ������ ��� 
	{
		puts("Fail to Open the file");
		return -1; //������ ���� ǥ���ϱ� ���� ���(EOF)
	}
	else {
		puts("Success to open the file");
	}
	while (!feof(rp)) // �������� �ִ� ���ڿ��� str1�� �Է�. ���Ͽ��� ������� �Ͼ�� ��ġ�� ������ ���̸� 1�� ����ϴ� feof�Լ�
	{
		fgets(str1, sizeof(str1), rp);
	}
	printf("%s", str1); //str1 ���
	fclose(rp); //���� ������ �ݴ� �Լ� fclose
}