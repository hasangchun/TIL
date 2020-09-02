#include <stdio.h>
#include <math.h>  //abs ���밪 ����ϱ� ���� �������
#include<stdlib.h>
#define MAXSIZE 8 //�ִ� ��
#define true 1 //���� ���� true, false�� 1, 0 ���� ����
#define false 0
typedef int boolean;  //�������� ���̱� ���� int �ڷ����� boolean �ڷ������� ���ڴ�.
typedef int element;
typedef struct {
	element *stack;  //array to store elements
	int max_size;  //maximum size
	int top;   //stack top
	int count;  
} Stack;

Stack* CreateStack(int size) {     //Stack ���� �޸� �Ҵ�, size ��ŭ stack ���� �޸��Ҵ�
	Stack *pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
	{
		return NULL;
	}
	pStack->stack = (element*)malloc((size) * sizeof(element));
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}
	pStack->max_size = size;
	pStack->top = -1;  
	pStack->count = 0;
	return pStack;
}

void push(Stack *pStack, element item) {
	if (pStack->top == pStack->max_size - 1) {
		printf("Stack is full");
		return;
	}
	pStack->stack[++pStack->top] = item;
}
element pop(Stack *pStack) {
	if (pStack->top < 0) {
		printf("Stack is empty");
		return 0;
	}
	return pStack->stack[pStack->top--];
}
element top(Stack *pStack) {
	if (pStack->top < 0) {
		printf("Stack is empty");
		return 0;
	}
	return pStack->stack[pStack->top];
}

void DestroyStack(Stack *pStack) {
	free(pStack->stack);
	free(pStack);
}

boolean check(Stack *pStack) {    //��ġ �������� �˻�
	int k = 0;
	boolean flag = true;
	while (k < pStack->top && flag)
	{	//���� ���̰ų� �밢���̸� ��ġ ���Ѵ�.
		if (pStack->stack[pStack->top] == pStack->stack[k] || abs(pStack->stack[pStack->top] - pStack->stack[k]) == (pStack->top) - k) {
			flag = false;
		}
		k++;
	}
	if (flag == true) {
		return flag;
	}
	else if (flag == false) {
		pStack->top--;  //���ǿ� ���� ���� ��� �ٽ� top���� 1�� ���ش�. 
		return flag;
	}
}
void put_queen(Stack *pStack) {
	if (check(pStack)) {
		if (pStack->top == (MAXSIZE - 1)) {  //���� �ϼ� �Ǿ����ϱ� count 1 ����
			pStack->count++;
			pStack->top--; //top�� �ٽ� 1 ���ش�.
		}
		else {
			for (int j = 0; j < MAXSIZE; j++) {
				push(pStack, j);  //�ݺ����� ���� �� �࿡�� ���� ������ �� ���� stack�� �����Ѵ�.
				put_queen(pStack); // ��� �Լ��� push�Լ������� top ������ ���� ������ �Ʒ��� ������ ��������.
				if (j == (MAXSIZE -1)) {  //j�� 7���� �Էµ� ���Ŀ��� ��Ģ�� ��߳��ٸ� �ٽ� top���� 1�� ���ش�.
					pStack->top--;
				}
			}
		}
	}
}
int main(void) {
	Stack *pStack = CreateStack(8);
	for (int i = 0; i < MAXSIZE; i++,pStack->top = -1) //�ݺ����� �ѹ��� ���� top�� �ٽ� -1�� �ʱ�ȭ���ش�.
	{
		push(pStack, i); //�ݺ����� ���� 0��° �࿡ ���� ������ �� ���� stack�� �����Ѵ�.
		put_queen(pStack);
	}
	printf("\n8-queens problem solution : %d��\n", pStack->count);
	DestroyStack(pStack);
}