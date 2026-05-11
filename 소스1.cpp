#include<iostream>
using namespace std;

class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	Power operator+ (Power op2);
	void getPower() { cout << kick << ' ' << punch << endl; }
};

Power Power::operator+(Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

int main() {
	Power a(3, 5),b(2, 1);
	Power c = a + b;
	a.getPower(); //3 5
	b.getPower(); //2 1
	c.getPower(); //4 4°¡ Ãâ·Â
	return 0;
}