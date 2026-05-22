#include<iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream& stream, Point a); //friend함수로 << 연산자 불러오기
};

ostream& operator << (ostream& stream, Point a) { //Point 객체를 출력해주는 스트림 연산자 << 구현하기
	stream << "(" << a.x << ", " << a.y << ")";
	return stream;
}

int main() {

	Point p(3, 4);
	cout << p << endl;

	Point q(1, 100), r(2, 200);
	cout << q << r << endl;
}