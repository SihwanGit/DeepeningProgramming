#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle() : Circle(1) {}
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

//두 Circle 객체를 교환하는 함수
void swap(Circle & c1, Circle & c2) { //Circle 객체의 레퍼런스를 매개변수로 받음.
	Circle temp;
	temp = c2;
	c2 = c1;
	c1 = temp;

} //void 형이므로 반환값은 없음

int main() {
	Circle c1(10), c2(20);
	cout << "c1의 넓이" << '\t' << "c2의 넓이" << endl;
	cout << c1.getArea() << "\t\t" << c2.getArea() << endl;
	swap(c1, c2);
	cout << c1.getArea() << "\t\t" << c2.getArea() << endl;
	return 0;
}