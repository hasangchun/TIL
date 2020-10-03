#include<stdio.h>
#include<string.h> //strcmp �Լ��� �̿��ϱ� ���� ���̺귯��
#include<stdlib.h> //malloc, free �Լ��� �̿��ϱ� ���� ���̺귯��
struct person
{
	char name[30];
	int score;
	int studentnumber;
};
int main()
{
	struct person *p, temp;
	int size, k;
	char seekname[30]; //ã�� �̸�
	char ch;
	printf("������ �Է��� ��� ���� �����ּ��� : ");
	scanf("%d", &size);
	p = (struct person *)malloc(sizeof(struct person)*size); //�Է��� ���ڸ�ŭ ����ü �迭�� �����Ҵ� �ޱ�
	for (int i = 0; i < size; i++)
	{
		printf("%d ��° ����� �й� : ", i + 1);
		scanf("%d", &p[i].studentnumber);  //�й� �Է�
		printf("%d ��° ����� �̸� : ", i + 1);
		while (getchar() != '\n');  //�Է¹��� ����
		k = 0;
		while (1) {
			ch = getchar();
			if (ch == '\n') break;
			p[i].name[k++] = ch;
		}  //�̸� �Է�
		p[i].name[k] = '\0'; // ���ڿ� ���� �ι��� �Է����ֱ�
		printf("%d ��° ����� ���� : ", i + 1);
		scanf("%d", &p[i].score); //���� �Է�
	}
	for (int i = 0; i < size; i++) // ���� ���ؼ� ���� ������ �������� ������
	{
		for (int j = 0; j < i; j++) {
			if (p[j].score < p[i].score) {
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	k = 0;
	printf("������ �˰� ���� ����� �̸� : ");
	while (getchar() != '\n'); //�Է¹��� ����
	while (1) //ã�� �̸� �Է�
	{
		ch = getchar();
		if (ch == '\n') break;
		seekname[k++] = ch;
	}
	seekname[k] = '\0'; // ���ڿ� ���� �ι��� �Է����ֱ�
	for (int i = 0; i < size; i++) {
		if (strcmp(seekname, p[i].name) == 0) //�̸��� �����ϸ� 0�� ��ȯ
		{
			printf("%s�� ����� %d�� �Դϴ�.", p[i].name, i + 1);
		}
	}
	free(p); //�Ҵ� ���� �޸� ��ȯ
}