#include<iostream>
using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; } //enqueue
	int get(int index) { return mem[index]; } //dequeue
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray {
private:
	int front = - 1;
	int rear = -1;
public:
	MyQueue(int n) : BaseArray(n) {}
	void enqueue(int n) { put(++rear, n); }
	int dequeue() { return get(++front); }
	int capacity() { return getCapacity(); }
	int length() { return rear - front; }
};

int main() {
	MyQueue mQ(100);
	int n, q;
	cout << "큐에 삽입하고 싶은 원소의 개수를 입력하세요>> ";
	cin >> n;
	cout << "큐에 삽입할 " << n << "개의 정수를 입력하라 >> ";
	for (int i = 0; i < n; i++) {
		cin >> q;
		mQ.enqueue(q);
	}
	cout << "큐의 용랑: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;

	return 0;
}