#include<stdio.h>
#include<stdlib.h>
#define true 1 //���� ���� true, false�� 1, 0 ���� ����
#define false 0
typedef int boolean;  //�������� ���̱� ���� int �ڷ����� boolean �ڷ������� ���ڴ�.
typedef int element;
typedef struct tTreeNode {  //����Ʈ�� ����� ����ü
	element data;
	struct tTreeNode *left, *right;
	boolean key;
} TreeNode;
typedef struct {  //������ ����ü
	TreeNode **stack;  //TreeNode�� ���������� ������ �迭
	int max_size;  // �ִ������
	int top;
} Stack;

TreeNode* CreateTree(TreeNode *left, element item, TreeNode *right)
{
	TreeNode *pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return NULL;
	pNewNode->data = item;
	pNewNode->left = left;
	pNewNode->right = right;
	pNewNode->key = false; // false�� �ʱ�ȭ ���ش�.
	return pNewNode;
}
TreeNode* MakeTree() {  //Ʈ���� ������ش�.
	TreeNode *eighteen = CreateTree(NULL, 18, NULL);
	TreeNode *seventeen = CreateTree(NULL, 17, eighteen);
	TreeNode *sixteen = CreateTree(NULL, 16, NULL);
	TreeNode *fifteen = CreateTree(NULL, 15, sixteen);
	TreeNode *fourteen = CreateTree(NULL, 14, fifteen);
	TreeNode *thirteen = CreateTree(seventeen, 13, fourteen);
	TreeNode *twelve = CreateTree(NULL, 12, thirteen);
	TreeNode *eleven = CreateTree(NULL, 11, NULL);
	TreeNode *ten = CreateTree(NULL, 10, eleven);
	TreeNode *nine = CreateTree(NULL, 9, ten);
	TreeNode *eight = CreateTree(NULL, 8, NULL);
	TreeNode *seven = CreateTree(NULL, 7, eight);
	TreeNode *six = CreateTree(NULL, 6, seven);
	TreeNode *five = CreateTree(nine, 5, six);
	TreeNode *four = CreateTree(NULL, 4, five);
	TreeNode *three = CreateTree(twelve, 3, four);
	TreeNode *two = CreateTree(NULL, 2, three);
	TreeNode *root = CreateTree(NULL, 1, two);

	return root;
}
boolean isEmpty(Stack *s) {
	return (s->top == -1);
}
boolean isFull(Stack *s) {
	return (s->top == s->max_size - 1);
}

Stack* CreateStack(int size) {     //Stack ���� �޸� �Ҵ�, size ��ŭ stack ���� �޸��Ҵ�
	Stack *pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
	{
		return NULL;
	}
	pStack->stack = (TreeNode**)malloc((size) * sizeof(TreeNode));
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}
	pStack->max_size = size;
	pStack->top = -1;
	return pStack;
}
void push(Stack *pStack, TreeNode* item) {
	if (isFull(pStack)) {
		printf("Stack is full");
		return;
	}
	pStack->stack[++pStack->top] = item;  // TreeNode ������ �� ���ÿ� ����
}
TreeNode* pop(Stack *pStack) {
	if (isEmpty(pStack)) {
		printf("Stack is empty");
		exit(0);
	}
	return pStack->stack[pStack->top--]; // TreeNode ���������� ���ÿ��� ������ �� �������ش�.
}
void DestroyStack(Stack *pStack) {
	free(pStack->stack);
	free(pStack);
}
void seekGoal(TreeNode* map, element goal) {
	Stack* pStack = CreateStack(50); // �����ְ� stack�� ����� 50���� �ؼ� ������ش�.
	boolean goalFound = false; //while�� Ż���� ���� flag 
	boolean finish = false; //while�� Ż���� ���� flag
	TreeNode * pMap = map;

	while (!goalFound) {
		if (pMap == NULL) {
			while (true) {
				if (isEmpty(pStack)) {
					printf("Goal is not founded.");
					finish = true; //while�� Ż���� ���� true�� �ٲپ��ְ� break���� ���� ����� �ݺ��� Ż��
					break;
				}
				pMap = pop(pStack); // branch point���� ��带 �ϳ��� �����ش�.
				if (pMap->key == true) {
					pMap->key = false; // goal path�� ����ϱ� ���� key�� false�� �Ͽ� �ٽ� stack�� ����
					push(pStack, pMap);
					pMap = pMap->left; // branch point���� �ݴ��� ���� �̵�
					break;
				}
			}
			if (finish == true) { // while�� Ż��
				break;
			}
		}
		else {
			if (pMap->data == goal) { //goal�� ã�Ҵٸ�
				goalFound = true;  //while�� Ż���� ���� true�� ����
				push(pStack, pMap); // goal path�� ����ϱ� ���� goal�� stack�� ����
				break; //����� �ݺ��� Ż��
			}
			else {
				if (pMap->left != NULL && pMap->right != NULL) {
					pMap->key = true;  //  branch point�̸� key�� true�� ����
					push(pStack, pMap);
				}
				else {
					push(pStack, pMap);
				}
			}
			pMap = pMap->right; // ���� ���� �������ش�.
		}

	}

	if (goalFound) { // goal�� ã�Ҵٸ�
		printf("The path to your goal is : ");
		while (true) {
			if (!isEmpty(pStack)) { // stack�� ������� �ʴٸ� pop�� ���� goal path ���
				printf("%d ", pop(pStack)->data);
			}
			else
				break;  // stack�� ����ִٸ� �ݺ��� Ż��
		}
	}
	DestroyStack(pStack); //���� �޸� �ݳ�
}
int main() {
	TreeNode *tTreeNode = MakeTree(); // Ʈ���� ������ش�. 
	int goal;
	printf("Input your goal : ");
	scanf("%d", &goal); // goal�� �Է¹޴´�.
	seekGoal(tTreeNode, goal); // goal�� ã���ش�.
}