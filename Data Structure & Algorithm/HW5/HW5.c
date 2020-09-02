#include<stdio.h>
#include<stdlib.h>
#include<string.h> //strcpy ����ϱ� ����.
#define true 1 //���� ���� true, false�� 1, 0 ���� ����
#define false 0
typedef int boolean; //�������� ���̱� ���� int �ڷ����� boolean �ڷ������� ���ڴ�.

typedef struct ListNode {
	int year;
	char picture_name[100];
	char director[30];
	struct ListNode *link;
}ListNode;  // ���
typedef struct {
	int count;
	ListNode *head;
	ListNode *pos;
}List; // Head ����ü
List* createList() {  // Head ����ü ���� �� �ʱ�ȭ
	List *pNewList = (List*)malloc(sizeof(List)); //���� �Ҵ�
	if (pNewList == NULL) {
		return NULL;
	}
	pNewList->count = 0;
	pNewList->head = NULL;
	pNewList->pos = NULL;
	return pNewList;
};
void insert_firstList(List* pList, int year, char picture_name[], char director[]) {
	//ó������ ��� ���� �� ��
	ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));

	pNewNode->year = year;
	strcpy(pNewNode->picture_name, picture_name);  //���ڿ� ����
	strcpy(pNewNode->director, director);  //���ڿ� ����

	pList->head = pNewNode; // Head ��尡 ���� ���� ��带 ����Ű�� �Ѵ�.
	pNewNode->link = NULL;  // ���� ���� ����� link�� NULL ����
	pList->count++;  //count 1����
};
void insertList(List* pList, ListNode *pPre, int year, char picture_name[], char director[]) {
	ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));

	pNewNode->year = year;
	strcpy(pNewNode->picture_name, picture_name); //���ڿ� ����
	strcpy(pNewNode->director, director); //���ڿ� ����


	if (pPre == NULL) {  //ù��° ���� ���� ���
		pNewNode->link = pList->head;
		//���� ���� ���� Head ��尡 �����״� ��带 ����Ŵ.
		pList->head = pNewNode;
		// Head ���� ���� ���� ��带 ����Ų��.
	}
	else {
		pNewNode->link = pPre->link;
		//pPre�� ����Ű�� ��带 ���� ���� ��尡 ����Ų��.
		pPre->link = pNewNode;
		// pPre�� ���� ���� ��带 ����Ų��.
	}

	pList->count++;  //count 1 ����
};

boolean search_year_List(List* pList, ListNode **pPre, ListNode **pLoc, int year) {
	// year�� �˻��� �Ѵ�.
	for (*pPre = NULL, *pLoc = pList->head; *pLoc != NULL; *pPre = *pLoc, *pLoc = (*pLoc)->link) {
		if ((*pLoc)->year == year) {
			//pLoc�� ����Ű�� year�� parameter�� ���� year�� ���ٸ� true�� ����.
			return true;
		}
		else if ((*pLoc)->year > year) {
			//pLoc�� ����Ű�� year�� parameter�� ���� year���� ũ�ٸ� ã���� �ϴ� year�� �Ѿ ���̴ϱ� �� �̻� �˻��ϴ� ���� �ǹ̰� ���� ������ break�� ���� �ݺ����� Ż���ϰ� false�� ����.
			break;
		}
	}
	return false;
};

void addListNode(List *pList, int year, char* picture_name, char* director) {
	ListNode *pPre = NULL, *pLoc = NULL;

	if (pList->count == 0) {  //ó�� Data node�� �����ϴ� ���
		insert_firstList(pList, year, picture_name, director);
		return;
	}
	boolean found = search_year_List(pList, &pPre, &pLoc, year);
	//pPre, pLoc�� �ּҰ��� parameter�� ���.
	if (!found) { //search �Ͽ� ���� pPre�� �̿��� data node ����.
		insertList(pList, pPre, year, picture_name, director);
	}
};
boolean print_picture_name(List* pList, int fromwhere, char picture_name[]) {
	if (fromwhere == 0 || pList->pos == NULL) {
		//ó�� ����ϴ� ��� pList�� pos�� pList�� head�� ����Ű�� ���(ù ��°���)�� ����Ű�� ��.
		pList->pos = pList->head;
	}
	else {
		pList->pos = pList->pos->link; //pos�� ����Ű�� �ִ� ����� link�� ����Ű�� ��带 pos�� ����Ŵ.
	}

	if (pList->pos != NULL) {
		//������ ��尡 �ƴϸ�, pos�� ����Ű�� �ִ� ����� picture name�� ����
		strcpy(picture_name, pList->pos->picture_name);
		return true;
	}
	else {
		return false;
	}
};
void deleteList(List *pList, ListNode *pPre, ListNode *pLoc)
{
	if (pPre == NULL) //ù ��° ��带 �����ϴ� ���
		pList->head = pLoc->link;
	else  // ù ��° �̿ܿ� ��带 �����ϴ� ���
		pPre->link = pLoc->link;
	free(pLoc);  //���� �޸� �ݳ�
	pList->count--;  //count 1 ����.
};

void removeList(List *pList, int year)
{
	ListNode *pPre = NULL, *pLoc = NULL;
	boolean found = search_year_List(pList, &pPre, &pLoc, year);
	//pPre, pLoc�� �ּҰ��� parameter�� �����Ͽ� search �Ѵ�.
	if (found) { //������ ��尡 �ִٸ�
		deleteList(pList, pPre, pLoc);
	}
};
void print_search_year(List *pList, int year)
{  //year�� �˻��Ͽ� ��ǰ�� �ִٸ� ���� ���, ���ٸ� ��ǰ�� ���ٰ� ���.
	ListNode *pPre = NULL, *pLoc = NULL;
	boolean found = search_year_List(pList, &pPre, &pLoc, year);
	//pPre, pLoc�� �ּҰ��� parameter�� �����Ͽ� search �Ѵ�.
	if (found) {
		printf("picture name : %s\n", pLoc->picture_name);
		printf("director : %s", pLoc->director);
	}
	else {
		printf("ã�� ��ǰ�� �����ϴ�.");
	}
}

void destroyList(List* pList) {
	ListNode *pDel = NULL, *pNext = NULL;
	for (pDel = pList->head; pDel != NULL; pDel = pNext) {
		// �ϳ��ϳ��� ���� ���� ���� �޸� �ݳ�.
		pNext = pDel->link;
		free(pDel);
	}
	free(pList); // ���������� Head node ���� �޸� �ݳ�
};
void clearInputBuffer()
{
	// �Է� ���ۿ��� ���ڸ� ��� ������ \n�� ������ �ݺ��� �ߴ�
	while (getchar() != '\n');
};
void main() {
	List* pList = createList();
	char key;
	int year;
	char picture_name[100];
	char director[30];

	while (true) {
		printf("Input a key(P, S, I, D, Q) : ");
		scanf("%c", &key);  //key �� �Է¹ޱ�

		if (key == 'P') {
			int n = 0;
			boolean check;
			do {
				check = print_picture_name(pList, n++, picture_name);
				if (check) {
					printf("%s  ", picture_name);
				}
			} while (check);
			printf("\n");

		}
		else if (key == 'S') {
			printf("input year : ");
			scanf("%d", &year);
			print_search_year(pList, year);
			//�Է� ���� year�� �˻��Ͽ� ��ǰ ���
		}
		else if (key == 'I') {
			printf("Input year : ");
			scanf("%d", &year);
			printf("Input picture name : ");
			scanf("%s", picture_name);
			printf("Input director : ");
			scanf("%s", director);
			addListNode(pList, year, picture_name, director);
			//�Է� ���� year, picture name, director data node�� ����.
		}
		else if (key == 'D') {
			printf("Input year : ");
			scanf("%d", &year);
			printf("Input picture name : ");
			scanf("%s", picture_name);
			printf("Input director : ");
			scanf("%s", director);
			removeList(pList, year);
			//year�� ���� data node ����
		}
		else if (key == 'Q') {
			break; //break�� ���� �ݺ��� Ż��.
		}
		clearInputBuffer(); //�Է� ���� ����, key�� ����Ű�� ���� �����.
		printf("\n");
	}
	destroyList(pList); //���� �޸� �ݳ�.
}