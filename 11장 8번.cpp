#include<iostream>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name="") {
			this->name = name;
			this->radius = radius;
		}
	friend ostream& operator << (ostream& stream, Circle circle);
	friend istream& operator >> (istream& stream, Circle& circle);
};

ostream& operator << (ostream& outs, Circle circle) { //outs, stream 등등 변수 이름은 맘대로
	outs << "(반지름" << circle.radius << "인 " << circle.name << ")";
	return outs;
}

istream& operator >> (istream& ins, Circle& circle) { //ins, stream 등등 변수 이름은 맘대로
	cout << "반지름 >> ";
	ins >> circle.radius;
	cout << "이름 >> ";
	ins >> circle.name;
	return ins;
}

int main() {
	Circle d, w;
	cin >> d >> w;
	cout << d << w << endl;

	return 0;
}