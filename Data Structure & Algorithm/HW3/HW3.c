#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct {
	element *stack;  //array to store elements
	int max_size;  //maximum size
	int top;   //stack top
} Stack;

Stack* CreateStack(int size) {     //Stack ���� �޸� �Ҵ�, size ��ŭ stack ���� �޸��Ҵ�
	Stack *pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
	{
		return NULL;
	}

	pStack->stack = (element*)malloc(size * sizeof(element));
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}
	pStack->max_size = size;
	pStack->top = -1;
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



int main(void) {
	int num;
	Stack *pStack = CreateStack(100);
	printf("Input a decimal number : ");
	scanf("%d", &num);  //�������Է¹ޱ�
	while (true) {
		if (num == 1) {
			push(pStack, num);  //������ ����1 ���ÿ� �Է�
			break;  //while �ݺ��� Ż��
		}
		push(pStack, num % 2);  //2�� ���� ������ ���ÿ� �Է�
		num = (num / 2);
	}

	printf("binary number : ");
	while (pStack->top >= 0) {
		num = pop(pStack);  //���ÿ��� �� �޾ƿ���
		printf("%d", num);
	}
	printf("\n");

	DestroyStack(pStack);  //���� �޸� �ݳ�
	pStack = NULL;

	return 0;
}

