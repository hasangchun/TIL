#include<stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char name[100];
	int slen;
	printf("�����Է� : ");
	scanf("%s", &name);

	slen = strlen(name); //���ڿ����� ���ϱ�
	for (int i = 0; i < slen; i++)
	{
		if (name[i] >= 97 && name[i] <= 122)  //�ƽ�Ű�ڵ� �̿�  , if(islower(name[i])) ��� �ص���.
		{
			printf("%c", name[i] - 32); // �빮�� �����,   toupper(name[i])��� �ص���.
		}
		else
			printf("%c", name[i]);
	}

}