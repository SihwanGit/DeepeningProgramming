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
	void put(int index, int val) { mem[index] = val; } //push
	int get(int index) { return mem[index]; } //pop
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
private:
	int top = -1;
public:
	MyStack(int n) : BaseArray(n) {}
	void push(int n) { put(++top, n); }
	int pop() {return get(top--); }
	int capacity() { return getCapacity(); }
	int length() { return top+1; }
};

int main() {
	MyStack mStack(100);
	int n, q;
	cout << "스택에 삽입하고 싶은 원소의 개수를 입력하세요>> ";
	cin >> n;
	cout << "스택에 삽입할 " << n << "개의 정수를 입력하라 >> ";
	for (int i = 0; i < n; i++) {
		cin >> q;
		mStack.push(q);
	}
	cout << "스택의 용랑: " << mStack.capacity() << ", 스택의 크기: " << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;

	return 0;
}



