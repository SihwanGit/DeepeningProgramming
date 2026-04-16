#include<iostream>
using namespace std;

class MyIntStack {
private:
	int p[10]; //최대 10개의 정수 저장
	int tos = -1; //스택의 꼭대기 인덱스
public:
	bool push(int n);
	bool pop(int& n);
};

bool MyIntStack::push(int n) {
	if (tos == 9) return false;
	else p[++tos] = n; return true;
}

bool MyIntStack::pop(int& n) {
	if (tos == -1) return false;
	else n = p[tos--]; return true;
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << " 번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty" << endl;
	}
	cout << endl;

	return 0;
}