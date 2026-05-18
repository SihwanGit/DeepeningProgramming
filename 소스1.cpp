#include<iostream>
using namespace std;

class Shape{
public:
	void print() {
		draw();
}
	virtual void draw() {
		cout << "Shape::draw() called" << endl;
	}
};

class Circle : public Shape {
public:
	virtual void draw() { //virtual 생략 가능
		cout << "Circle::draw() called" << endl;
	}
};

int main() {
	Shape* pS = new Shape();
	pS->print(); //Shape::drea()가 호출
	delete pS;

	Shape* pC = new Circle();
	pC->print(); //Circle::draw()가 호출
	delete pC;
	return 0;
}