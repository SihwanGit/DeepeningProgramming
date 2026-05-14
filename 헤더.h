#pragma once
#include<iostream>
#include<string>
using namespace std;

class Point {
protected:
	int x, y;
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void show() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};

class ColorPoint : public Point {
	string color;
public:
	void setColor(string color) { this->color = color; x = 5; }
	void showColorPoint();
	bool equal(ColorPoint p);
};