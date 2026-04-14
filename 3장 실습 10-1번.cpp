#include<iostream>
using namespace std;

class Add { //더하기 클래스
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
inline void Add::setValue(int x, int y) { a = x, b = y; }
inline int Add::calculate() {return a + b;}

class Sub { //빼기 클래스
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
inline void Sub::setValue(int x, int y) {a = x, b = y;}
inline int Sub::calculate() {return a - b;}

class Mul { //곱하기 클래스
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
inline void Mul::setValue(int x, int y) {a = x, b = y;}
inline int Mul::calculate() {return a * b;}

class Div { //나누기 클래스
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};
inline void Div::setValue(int x, int y) {a = x, b = y;}
inline int Div::calculate() {return a / b;}

int main() {
	Add a;
	Sub s;
	Mul m;
	Div d;
	int x, y, r;
	char c;

	while (1) {
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> x >> y >> c;
		switch (c)
		{
		case '+':
			a.setValue(x, y);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(x, y);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(x, y);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(x, y);
			cout << d.calculate() << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}