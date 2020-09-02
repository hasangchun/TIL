#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef int Element;
#define true 1
#define false 0

typedef struct Heap {
	Element *heapArray; // array to store items
	int maxSize; // maximum size of heapArray
	int size; // ���� heapArray�� ���ִ� ����
	int last;
} Heap;

Heap* CreateHeap(int size) {
	Heap* pNewHeap = (Heap*)malloc(sizeof(Heap)); //���� �޸� �Ҵ�
	if (pNewHeap == NULL) {
		return NULL;
	}
	pNewHeap->heapArray = (Element*)malloc(size * sizeof(Element)); //���� �޸� �Ҵ�
	if (pNewHeap->heapArray == NULL) {
		free(pNewHeap);
		return NULL;
	}
	pNewHeap->maxSize = size;  // �ʱ�ȭ
	pNewHeap->size = 0; // �ʱ�ȭ
	pNewHeap->last = -1; // �ʱ�ȭ
	return pNewHeap;
}
void ReheapUp(Heap *pHeap, int index)
{
	int parentIndex = 0;
	if (index <= 0 || index >= pHeap->size) //base case
		return;
	parentIndex = (index - 1) / 2;
	if (pHeap->heapArray[index] > pHeap->heapArray[parentIndex]) { // true : general case, false : base case
		// parent�� child�� data�� �ٲٴ� ����
		Element temp = pHeap->heapArray[index];
		pHeap->heapArray[index] = pHeap->heapArray[parentIndex];
		pHeap->heapArray[parentIndex] = temp;
		ReheapUp(pHeap, parentIndex); // recursion
	}
}

void InsertHeap(Heap *pHeap, Element data)
{
	if (pHeap->size >= pHeap->maxSize) {
		printf("Heap is full!\n");
		return;
	}
	pHeap->heapArray[++pHeap->last] = data;
	// ++last �� �� ������ �迭�� 0���� �����ϱ� ������ last�� 1 ������Ű�� �ε����� ����Ѵ�.
	// shape property
	pHeap->size++; //size 1 ����
	ReheapUp(pHeap, pHeap->last); // order property
}


void ReheapDown(Heap *pHeap, int index)
{
	if (index < 0 || index >= pHeap->size)
		return;
	if (index * 2 + 1 < pHeap->size) {     // left subtree�� �����ϴ��� Ȯ���ϰ� ������ �ٷ� �Լ� ����
		//right subtree�� Ȯ������ ���� ������ Heap�� complete binary tree �̱� ������ ���ʿ� subtree�� ������ �����ʿ��� subtree�� ����.
		int maxChild = index * 2 + 1;      // maxchild�� left�� ����
		if (maxChild + 1 < pHeap->size && pHeap->heapArray[maxChild + 1] > pHeap->heapArray[maxChild])
			// right subtree�� �����ϴ��� Ȯ���ϰ�, right subtree�� ���� left subtree�� ������ ũ�ٸ� maxChild++�� ���� right�� �ٲ��ش�.
			maxChild++;
		if (pHeap->heapArray[maxChild] > pHeap->heapArray[index]) { //true: general case, false: base case
			// parent�� child�� data�� �ٲٴ� ����
			Element temp = pHeap->heapArray[index];
			pHeap->heapArray[index] = pHeap->heapArray[maxChild];
			pHeap->heapArray[maxChild] = temp;
			ReheapDown(pHeap, maxChild); //recursion
		}
	}
}

int DeleteHeap(Heap *pHeap, Element *pDataOut)
{
	if (pHeap->size <= 0) {
		printf("Heap is empty!\n");
		return false;
	}
	*pDataOut = pHeap->heapArray[0];
	pHeap->heapArray[0] = pHeap->heapArray[pHeap->last--]; // heapArray�� ������ ���� root�� �����ϰ� last�� 1 ���ҽ�Ų��.
	pHeap->size--; //size 1 ����
	ReheapDown(pHeap, 0);
	return true;
}



int SelectK(Heap *pHeap, int k) {
	int dataOut;
	int holdOut;
	int originalSize;

	if (k > pHeap->size) {
		return false;
	}
	originalSize = pHeap->size;
	for (int i = 0; i < k; i++) { //k�� �ݺ��Ͽ� root data�� ����
		DeleteHeap(pHeap, &dataOut);
		pHeap->heapArray[pHeap->size] = dataOut; //reconstruct heap�� ���ؼ� root data�� heapArray�� ���� 
	}
	holdOut = pHeap->heapArray[0]; //�츮�� ���ϴ� data�� holdOut�� ����

	while (pHeap->size < originalSize) {
		pHeap->size++;
		pHeap->last++;
		ReheapUp(pHeap, pHeap->last);
	}
	return holdOut;
}

void DestroyHeap(Heap *pHeap) { //���� �޸� �ݳ�
	free(pHeap->heapArray);
	free(pHeap);
}

void MakeHeap(Heap *pHeap) {
	int num;
	srand(time(NULL)); // ��� ������ �ٲ�� �Ѵ�.
	printf("unsorted array : ");

	for (int i = 0; i < 10; i++) {
		num = (rand() % 100) + 1;
		printf("%d ", num);
		InsertHeap(pHeap, num); // 1 ~ 100 ������ ���� 10���� heap�� ����
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", pHeap->heapArray[i]);
	}
}

void Test(Heap *pHeap) {
	int key;

	printf("\n�� ��° ��Ҹ� �����Ͻðڽ��ϱ� ? (0 ~ 19)\n"); //ũ�Ⱑ 20�� array�� ������� �����̴�.
	scanf("%d", &key);

	printf("\n%d �Դϴ�.", SelectK(pHeap, key));

}

int main() {
	Heap *pHeap = CreateHeap(20);
	MakeHeap(pHeap);
	Test(pHeap);

	DestroyHeap(pHeap);
}