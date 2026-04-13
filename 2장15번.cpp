#include<iostream>
using namespace std;

int main() {
	int a, b; // 입력할 두 정수
	char c; //연산자
	while (1) {
		cout << "? ";
		cin >> a >> c >> b;
		if (c == '+') cout << a << " " << c << " " << b << "= " << a + b << endl; //더하기
		else if (c == '-') cout << a << " " << c << " " << b << "= " << a - b << endl; //빼기
		else if (c == '*') cout << a << " " << c << " " << b << "= " << a * b << endl; //곱하기
		else if (c == '/') cout << a << " " << c << " " << b << "= " << a / b << endl; //몫
		else if (c == '%') cout << a << " " << c << " " << b << "= " << a % b << endl; //나머지
		else break; //종료
	}
	

	return 0;
}