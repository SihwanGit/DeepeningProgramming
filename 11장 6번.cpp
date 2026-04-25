#include<iostream>
#include<cmath>
using namespace std;

int main() {
	cout.setf(ios::left); //이걸 해야 왼쪽 정렬됨.
	cout.width(15);
	cout << "Number";
	cout.width(15);
	cout << "Square";
	cout.width(15);
	cout << "Square Root";
	cout << endl;

	for (int i = 0; i < 10; i++) {
		cout.fill('_');
		cout.width(15);
		cout << 5 * i;
		cout.fill('_');
		cout.width(15);
		cout << 25 * i * i;
		cout.fill('_');
		cout.width(15);
		cout.precision(3);
		cout << sqrt(5 * i);
		cout << endl;
	}

	return 0;
}