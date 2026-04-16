#include<iostream>
using namespace std;

class Accumulator {
private:
	int value;
public:
	Accumulator(int value) { this->value = value; }
	Accumulator& add(int n);
	int get();
};

Accumulator& Accumulator::add(int n) {
	value += n;
	return *this;
	//객체의 맴버 함수가 객체 자신에게 영향을 줘야할 때 this를 사용한다.
	//Accumulator의 참조변수를 반환해야하므로 this에 *를 붙여 Accumulator객체를 반환한다.
}

int Accumulator::get() {
	return value;
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);
	cout << acc.get() << endl;
	return 0;
}