#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle(); //기본 생성자
	Circle(int r);
	Circle(double dr);
	double getArea();
};

Circle::Circle() : Circle(1) {} //위임 생성자 사용
//Circle(int r)을 호출해 r = 1을 수행한다.

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::Circle(double dr) {
	radius = dr;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle dount; //초기화를 생략하고 Circle() 생성자 사용.
	double area = dount.getArea();
	cout << "dount 면적은 " << area << endl;

	Circle pizza(30); //Circle(int r) 생성자 사용
	area = pizza.getArea();
	cout << "pizza의 면적은 " << area << endl;
	return 0;
}