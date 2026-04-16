#include<iostream>
using namespace std;

class MyIntStack {
private:
	int *p; //최대 10개의 정수 저장
	int size; //배열의 크기
	int tos = -1; //스택의 꼭대기 인덱스
public:
	MyIntStack():MyIntStack(10) {} //기본생성자 호출 시 size = 10으로 설정
	MyIntStack(int size);
	MyIntStack(const MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int& n);
};

MyIntStack::MyIntStack(int size) { //생성자
	this->size = size;
	p = new int[size];
}

MyIntStack::MyIntStack(const MyIntStack& s) { //복사생성자 -> 깊은 복사가 되게끔 작성
	this->size = s.size; //이건 private여도 가능하네.
	this->tos = s.tos;
	this->p = new int[size];
	for (int i = 0; i < tos; i++) this->p[i] = s.p[i];
}

MyIntStack::~MyIntStack() { //소멸자
	delete[] p;
}

bool MyIntStack::push(int n) {
	if (tos == size-1) return false;
	else p[++tos] = n; return true;
}

bool MyIntStack::pop(int& n) {
	if (tos == -1) return false;
	else n = p[tos--]; return true;
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a; //초기화하며 생성할 떈 묵시적으로 복사생성자 생성
	b.push(30);

	int n;
	a.pop(n); //스택 a 팝
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;
	return 0;
}