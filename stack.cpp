#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

inline void error(const char* message) {
	printf("%d\n", message);
}

const int MAX_STACK_SIZE = 20;

class ArrayStack {
	int top;
	int data[MAX_STACK_SIZE];

public:
	ArrayStack() { top = -1; }
	~ArrayStack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX_STACK_SIZE - 1; }

	void push(int e) {
		if (isFull())error("���� ��ȭ ����");
		data[++top] = e;
	}

	int pop() {
		if (isEmpty())error("���� ���� ����");
		return data[top--];
	}

	int peek() {
		if (isEmpty()) error("���� ���� ����");
		return data[top];
	}

	void display() {
		printf("[���� �׸��� �� = %2d] ==> ", top + 1);
		for (int i = 0; i <= top; i++)
		{
			printf("<%2d>", data[i]);
		}
		printf("\n");
	}
};

int main() {
	ArrayStack stack;

	for (int i = 1; i <= 10; i++)
	{
		stack.push(i);
	}
	stack.display();
	printf("%2d�� ���½��ϴ�.\n", stack.pop());
	printf("%2d�� ���½��ϴ�.\n", stack.pop());
	printf("%2d�� ���½��ϴ�.\n", stack.pop());

	stack.display();

}