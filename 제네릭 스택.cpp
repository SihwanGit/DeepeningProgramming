#include<iostream>
using namespace std;

template <class T>
class MyStack {
	int tos; //top of Stack
	T data[100]; //크기가 100인 T타입 배열
public:
	MyStack();
	void push(T element); //원소 넣기
	T pop(); //T타입 원소 출력
	//Full하고 Empty가 없는 반쪽짜리 스택이긴 함ㅋㅋㅋ
};

template<class T>
MyStack<T>::MyStack() {
	tos = -1;
}

template<class T>
void MyStack<T>::push(T element) {
	if (tos == 99) {
		cout << "stack is full" << endl;
		return;
	}
	data[++tos] = element;
}

template<class T>
T MyStack<T>::pop() {
	T retData;
	if (tos == -1) {
		cout << "stack empty" << endl;
		return 0;
	}
	retData = data[tos--];
	return retData;
}

int main() {
	MyStack<int> iStack; //MyStack<int>로 하면 T가 int 형이 된다.
	iStack.push(3);
	cout << iStack.pop() << endl;

	return 0;
}