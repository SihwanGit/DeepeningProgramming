#include<iostream>
using namespace std;

template <class T>
bool equalArrays(T x[], T y[], int size) {
	for (int i = 0; i < size; i++) {
		if (x[i] != y[i]) return false;
	}
	return true;
}

int main() {
	int x1[] = { 1, 10, 100, 5, 4 };
	int y1[] = { 1, 10, 100, 5, 4 };
	if (equalArrays(x1, y1, 5)) cout << "같다." << endl;
	else cout << "다르다" << endl;
	//같다 출력

	double x2[] = { 1.1, 10.2, 100.3, 5.4, 4.4 };
	double y2[] = { 1.1, 10.2, 100.3, 5.4, 4.5 };
	if (equalArrays(x2, y2, 5)) cout << "같다." << endl;
	else cout << "다르다" << endl;
	//다르다 출력

	return 0;
}