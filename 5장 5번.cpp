#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};

//Circle 객체 a의 반지름에 객체 b의 반지름을 더하는 함수
void increaseBy(Circle &a, Circle &b) { //두 Circle 객체 a,b를 매개변수로 받는다.
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
} //void 형이므로 반환값은 없다.

int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();
	return 0;
}