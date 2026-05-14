#include"Çì´õ.h"

void ColorPoint::showColorPoint() {
	cout << color << ":";
	show();
}

bool ColorPoint::equal(ColorPoint p) {
	if (x == p.x && y == p.y && color == p.color) return true;
	else return false;
}