#include<iostream>
using namespace std;

class Shape {
public:
	virtual void draw() {
		//draw(); 여기다 draw()를 넣어도 무한루프 발생
		cout << "--Shape--" << endl;
	}
};

class Circle : public Shape {
public:
	int x;
	virtual void draw() { //virtual 생략 가능
		Shape::draw();
		//draw(); //이렇게 그냥 draw()라고만 해버리면 무한루프로 오류 발생
		cout << "Circle" << endl;
	}
};

int main() {
	Circle c;
	Shape* pS = &c;

	pS->draw();
	pS->Shape::draw();

	return 0;
}