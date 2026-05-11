#include<iostream>
#include"Çì´õ.h"
using namespace std;

class Rect;

int main() {
	Rect a(3, 4), b(4, 5);
	RectManager man;
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;

	return 0;
}