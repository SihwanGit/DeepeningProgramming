#include<iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle() { //생성자를 사용하면 private에서 초기화 가능함?
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
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