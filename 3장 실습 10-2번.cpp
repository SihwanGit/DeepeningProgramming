#include"3장 실습 10번.h"

inline void Add::setValue(int x, int y) { a = x, b = y; } //더하기 구현부
inline int Add::calculate() { return a + b; }

inline void Sub::setValue(int x, int y) { a = x, b = y; } // 빼기 구현부
inline int Sub::calculate() { return a - b; }

inline void Mul::setValue(int x, int y) { a = x, b = y; } //곱하기 구현부
inline int Mul::calculate() { return a * b; }

inline void Div::setValue(int x, int y) { a = x, b = y; } //나누기 구현부
inline int Div::calculate() { return a / b; }

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