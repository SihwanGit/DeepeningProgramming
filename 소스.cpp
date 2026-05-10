#include<iostream>
using namespace std;

class Circle {
	int radius;
public:
	//Circle() : Circle(1) {} 위임생성자
	//Circle() { radius = 1; }
	//Circle(int r) { radius = r; }
	Circle(int r = 1) { radius = r; }
	//위 두개의 생성자를 이거 하나로 압축할 수 있다.
	//위임생성자로도 가능하다.
	int getRadius() { return radius; }
};

void star(int a = 5) {
	for (int i = 0; i < a; i++) cout << "*";
	cout << endl;
}

void msg(int id = 0, string s = "") {
	cout << id << ' ' << s << endl;
}

void f(char c = ' ', int line = 1) {
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < 10; j++) {
			cout << c;
		}
		cout << endl;
	}
}

int main() {
	star();
	star(10);
	cout << '\n';

	msg();
	msg(1);
	msg(2, "Hi");
	
	f();
	f('%');
	f('$', 4);

	Circle c1, c2(10); 
	//디폴트 매개변수를 써서 기본생성자를 포함한 생성자를 구현한 것이다.
	//위임생성자 쓰는 것보다 이게 더 편한듯.
	cout << endl << c1.getRadius() << ' ' << c2.getRadius() << endl;
	return 0;
}