#include <iostream>
using namespace std;
const int MAX_SIZE = 20; // �ִ� ũ�� ��� 20

class Queue {
private:
	int *data; // queue
	int front;
	int rear;
public:
	Queue(int size);  //������
	~Queue();   //�Ҹ���
	bool is_empty();  //queue�� ����ִ� Ȯ���ϴ� �Լ�
	bool is_full();  //queue�� �� ���ִ� Ȯ���ϴ� �Լ�
	void Enqueue(int x);  //queue�� data ����
	int Dequeue();  //FIFO ������ data ����
	int QueueFront(); //�տ� �ִ� data�� �˻�
	int QueueRear(); //�ڿ� �ִ� data�� �˻�
	void print(); // ����ϴ� �Լ�
	void test();  //�׽�Ʈ �Լ�
};

Queue::Queue(int size) {
	data = (int*)malloc(size * sizeof(int)); //size��ŭ ���� �޸� �Ҵ�
	if (data == NULL) {
		free(data);
	}
	front = -1; //front -1�� �ʱ�ȭ
	rear = -1; //rear -1�� �ʱ�ȭ
}

Queue::~Queue() {
	free(data); //���� �޸� �ݳ�
}

bool Queue::is_empty() {
	return front == rear;
}

bool Queue::is_full() {
	return ((rear + 1) % MAX_SIZE) == front; //����ť�̴�.
}

void Queue::Enqueue(int x) {
	if (is_full()) {
		cout << "ť�� ��ȭ���� �Դϴ�." << '\n';
		return;
	}
	rear = (rear + 1) % MAX_SIZE; //����ť�̴�. 
	data[rear] = x;
}

int Queue::Dequeue() {
	if (is_empty()) {
		cout << "ť�� ����ֽ��ϴ�." << '\n';
		return 0;
	}
	front = (front + 1) % MAX_SIZE; //����ť�̴�. 
	return data[front];
}

int Queue::QueueFront() {
	return data[(front + 1) % MAX_SIZE];
}

int Queue::QueueRear() {
	return data[rear % MAX_SIZE];
}

void Queue::print() {
	cout << "Queue : ";
	if (!is_empty()) {
		int num = front;
		do {
			num = (num + 1) % (MAX_SIZE);
			cout << data[num] << " ";
			if (num == rear) { //��� �� ��� �ߴٴ� �ǹ��̹Ƿ� break���� ���� �ݺ��� Ż��
				break;
			}
		} while (num != front);
	}
	cout << "\n";
}

void Queue::test() {
	for (int i = 1; i < 20; i += 2) {
		Enqueue(i);
	}    //  1,3,5,7,9,11,13,15,17,19 �� queue�� �ִ´�.

	print(); //���

	for (int i = 0; i < 7; i++) {
		Dequeue();
	}    // ó���� �� ������ 7���� ����.

	print();  //���

	for (int i = 25; i > 15; i--) {
		Enqueue(i);
	}    //  25,24,23,22,21,20,19,18,17,16 �� queue�� �ִ´�.

	print(); //���

	for (int i = 0; i < 5; i++) {
		Dequeue();
	}    // ó���� �� ������ 5���� ����.

	print();  //���
}


int main() {
	Queue q(20);
	q.test();

	return 0;
}