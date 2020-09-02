#include <iostream>
using namespace std;

typedef struct QueueNode { //Data node ����ü
	int data;
	struct QueueNode *link;
}QueueNode;

class Queue {
private:
	QueueNode *front;
	QueueNode *rear;
public:
	Queue();  //������
	bool is_empty();  //queue�� ����ִ� Ȯ���ϴ� �Լ�
	bool is_full();  //queue�� �� ���ִ� Ȯ���ϴ� �Լ�
	void Enqueue(int data);  //queue�� data ����
	int Dequeue();  //FIFO ������ data ����
	void print(); // ����ϴ� �Լ�
	void test();  //�׽�Ʈ �Լ�
};

Queue::Queue() {
	front = 0;
	rear = 0;
}

bool Queue::is_empty() {
	return front == NULL;
}

bool Queue::is_full() {
	return 0;
}

void Queue::Enqueue(int data) {
	QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode)); //���� �޸𸮸� �Ҵ� �޾Ƽ� data ����
	temp->data = data;
	temp->link = NULL;
	if (is_empty()) {
		front = temp;
		rear = temp;
	}
	else {
		rear->link = temp; //link�� ���� queue ����
		rear = temp; //rear�� ������ data ��带 ����Ŵ.
	}
}

int Queue::Dequeue() {
	QueueNode *temp = front; //temp�� front�� ����Ű�� ��带 ����Ű�� ��.
	int data;
	if (is_empty()) {
		cout << "ť�� ����ֽ��ϴ�.";
		return 0;
	}
	else {
		data = temp->data;
		front = front->link;
		if (front == NULL) {
			rear = NULL;
		}
		free(temp); //���� �޸� �ݳ�
		return data;
	}
}

void Queue::print() {
	QueueNode *p;
	cout << "Queue : ";
	for (p = front; p != NULL; p = p->link) { //�ݺ����� ���� queue ���
		cout << p->data << " ";
	}
	cout << "\n";
}

void Queue::test() {
	for (int i = 2; i < 20; i += 2) {
		Enqueue(i);
	}    //  2,4,6,8,10,12,14,16,18 �� queue�� �ִ´�.

	print(); //���

	for (int i = 0; i < 7; i++) {
		Dequeue();
	}    // ó���� �� ������ 7���� ����.

	print();  //���

	for (int i = 7; i > 2; i--) {
		Enqueue(i);
	}    //  7,6,5,4,3 �� queue�� �ִ´�.

	print(); //���

	for (int i = 0; i < 5; i++) {
		Dequeue();
	}    // ó���� �� ������ 5���� ����.

	print();  //���
}


int main() {
	Queue q;
	q.test(); //�׽�Ʈ �Լ�

	return 0;
}