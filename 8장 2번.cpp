#include<iostream>
#define SIZE 5
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; } //디폴트매개변수를 사용하면 기본 생성자 없어도 돌아감.
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }
};

void Max(NamedCircle *cir) { //NamedCircle의 객체 배열을 매개변수로 받아 최대값을 구하는 함수
	int max = 0;
	for (int i = 0; i < SIZE; i++) {
		if (cir[i].getRadius() > cir[max].getRadius()) max = i;
	}
	cout << "가장 면적이 큰 피자는 " << cir[max].getName() << "입니다. \n";
} //void형이므로 반환값은 없다.

int main() {
	NamedCircle pizza[SIZE];
	int r;
	string n;
	cout << SIZE << "개의 정수의 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ">> ";
		cin >> r >> n;
		pizza[i].setRadius(r);
		pizza[i].setName(n);
	}
	Max(pizza);

	return 0;
}