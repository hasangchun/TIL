#include<stdio.h>
#include<stdlib.h>
int main()
{
	int x, y = 0;
	int **map;
	int **map2;

	printf("���� ���� :");
	scanf("%d", &x);
	printf("���� ���� :");
	scanf("%d", &y);
	
	map = (int**)malloc(x * sizeof(int*)); //2��
	for (int i = 0; i < x; i++) {  //���پ� �ִ� �޸� �Ҵ�
		*(map + i) = (int*)malloc(y * sizeof(int));
	}

	map2 = (int**)malloc(y * sizeof(int*)); //2��
	for (int i = 0; i < y; i++) {  //���پ� �ִ� �޸� �Ҵ�
		*(map2 + i) = (int*)malloc(x * sizeof(int));
	}

	for (int p = x - 1; p >= 0; p--) {
		for (int q = y - 1; q >= 0; q--) {
			printf("A%d%d : ", x - p, y - q);
			scanf("%d", &map[x - p - 1][y - q - 1]);
		}
	}
	printf("�Էµ� ����� ��\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("%3d", map[i][j]);
		}printf("\n");
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++) {
		map2[j][i] = map[i][j];
		}
	}

	printf("Tranpose ���\n");
	for (int j = 0; j < y; j++) {
		for (int i = 0; i < x; i++) {
			printf("%3d", map2[j][i]);
		}printf("\n");
	}
}