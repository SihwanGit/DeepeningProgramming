#include<iostream>
using namespace std;
#define SIZE 10 //stack size

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack {
private:
	int top = -1;
	int stack[SIZE];
public:
	virtual bool push(int n) {
		if (top >= SIZE-1) return false;
		else {
			stack[++top] = n;
			return true;
		}
	}
	virtual bool pop(int& n) {
		if (top <= -1) return false;
		else {
			n = stack[top--];
			return true;
		}
	}
	virtual int size() {
		return top + 1;
	}
};

int main() {
	IntStack intStack;
	int n;
	cout << "스택에 들어갈 정수를 입력하세요 >> ";
	for (int i = 0; i < SIZE; i++) {
		cin >> n;
		intStack.push(n);
	}
	cout << "스택의 정수들을 출력합니다 >> ";
	for (int i = 0; i < SIZE; i++) {
		intStack.pop(n);
		cout << n << ' ';
	}
	cout << endl;
	
	return 0;
}