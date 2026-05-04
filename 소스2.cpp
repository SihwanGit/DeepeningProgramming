#include<iostream>
using namespace std;
#include"헤더.h" //헤더파일에 선언부 이동

Circle::Circle() { //생성자를 사용하면 private에서 초기화 가능함?
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}

Circle::~Circle() { //소멸자
	cout << "반지름 " << radius << "인 원 소멸" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle dount; //초기화를 생략하고 Circle() 생성자 사용.
	double area = dount.getArea();
	cout << "dount 면적은 " << area << endl <<endl;

	Circle pizza(30); //Circle(int r) 생성자 사용
	area = pizza.getArea();
	cout << "pizza의 면적은 " << area << endl<< endl;
	return 0;
}