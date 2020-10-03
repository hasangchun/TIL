#include<stdio.h>
#include<math.h> //������ ���ϴ� �Լ� abs�� �̿��ϱ� ���� ���̺귯��
int calculator(char map[7][7]) //��ȯ���� int�� �Լ�
{
	int i = 0;
	int j = 0;
	int before_x = 0;
	int before_y = 0;
	int after_x = 0;
	int after_y = 0;
	int count = 0;
	int length = 0;
	int all_length = 0; //�� �ִܰŸ�

	for (int k = 0; k < 4; k++) //'X' �װ��� ã�� ���ؼ� �׹� �ݺ��Ѵ�.
	{
		if (map[i][j] == 'X') //(0,0)�� 'X'�� �ִ� ���
		{
			map[i][j] = '0';
			continue;
		}
		for (int x = 1; x <= 11; x++) // map[i][j]��� �Ҷ� �����̸������ ȸ���ϸ� j+, i+,   j-, j-, i-, i-,   j+, j+, j+, i+, i+, i+,   j-, j-, j-, j-, i-, i-, i-, i- �� ���� ��Ģ�� ���´�. �׶� �ִ�� �����ִ°��� j�� ���������� 11�� +�Ǵ°���̴�.
		{
			if (x % 2 != 0) //Ȧ���϶��� �÷���
			{
				for (count = 0; count < x; count++)  //1�̸� �ѹ��� �÷���, 3�̸� �������÷��� ���� ���·� �ݺ��Ǳ� ����
				{
					if (i < 0 || j < 0) //�迭���� ���̳ʽ��� ���� j ++�ϰ� �Ѿ��
					{
						j++;
					}
					else if (map[i][j] == 'X') // 'X'�߰��ϸ� �׶� ��ǥ i,j�� after_x , after_y�� ���� �ϰ� break�� ����� �ݺ��� Ż��
					{
						after_x = i;
						after_y = j;
						break;
					}
					else j++; // �������� j  1����
				}
				for (count = 0; count < x; count++) //1�̸� �ѹ��� �÷���, 3�̸� ������ �÷��� ���� ���·� �ݺ��Ǳ� ����
				{
					if (i < 0 || j < 0) //�迭���� ���̳ʽ��� ���� i++�ϰ� �Ѿ��
					{
						i++;
					}
					else if (map[i][j] == 'X')  // 'X'�߰��ϸ� �׶� ��ǥ i,j�� after_x , after_y�� ���� �ϰ� break�� ����� �ݺ��� Ż��
					{
						after_x = i;
						after_y = j;

						break;
					}
					else i++;  //�������� i  1����
				}
			}
			else //¦���϶��� ���̳ʽ�
			{
				for (count = 0; count < x; count++) //2�̸� �ι��� ���̳ʽ�, 4�̸� �׹��� ���̳ʽ� ���·� �ݺ��Ǳ� ����
				{
					if (i < 0 || j < 0) //�迭���� ���̳ʽ��� ���� j--�ϰ� �Ѿ��
					{
						j--;
					}
					else if (map[i][j] == 'X')// 'X'�߰��ϸ� �׶� ��ǥ i,j�� after_x , after_y�� ���� �ϰ� break�� ����� �ݺ��� Ż��
					{
						after_x = i;
						after_y = j;
						break;
					}
					else j--; //�������� j  1����
				}
				for (count = 0; count < x; count++) //2�̸� �ι��� ���̳ʽ�, 4�̸� �׹��� ���̳ʽ� ���·� �ݺ��Ǳ� ����
				{
					if (i < 0 || j < 0) //�迭���� ���̳ʽ��� ���� i--�ϰ� �Ѿ��
					{
						i--;
					}
					else if (map[i][j] == 'X') // 'X'�߰��ϸ� �׶� ��ǥ i,j�� after_x , after_y�� ���� �ϰ� break�� ����� �ݺ��� Ż��
					{
						after_x = i;
						after_y = j;
						break;
					}
					else i--; //�������� i  1����
				}
			}
			if (map[i][j] == 'X') //'X'�� �߰��ϸ� 'O'�� �ٲپ��ְ� break�� ����� �ݺ��� Ż��
			{
				map[i][j] = 'O';
				break;
			}
		}
		if (k == 0)  //ù��° �϶��� (0,0)�� �߰� ������ �Ÿ��� ���Ѵ�.
		{
			length = (after_x - 0) + (after_y - 0);
		}
		else if (k != 0) //�������� ���� ������ ���ϴ� �Լ� abs�� �̿��ؼ� �߰� ���� ������ �߰� ������ �Ÿ��� ���Ѵ�.
		{
			length = abs((after_x - before_x)) + abs((after_y - before_y));
		}
		before_x = after_x;  //�߰��� ���� ��ǥ�� before_x�� ����
		before_y = after_y; //�߰��� ���� ��ǥ�� before_y�� ����
		all_length += length; //���� �ִܰŸ��� all_length�� �����ش�.
	}
	return all_length; // �� �ִܰŸ� ��ȯ
}
int main()
{
	char map[7][7] = { 'O','O','O','X','O','O','O',
	'O','O','O','O','O','O','O',
	'X','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','X','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','X' };   //map����

	int shorttest = 0;
	for (int x = 0; x < 7; x++)//map ���
	{
		for (int y = 0; y < 7; y++)
		{
			printf("%3c", map[x][y]);
		}
		printf("\n");
	}
	shorttest = calculator(map);
	printf("�ִܰŸ� : %d", shorttest); //�ִܰŸ� ���
}