#include<iostream>
#include"Shape.h"
using namespace std;

void Shape::print() {
	draw();
}

void Shape::draw() {
	cout << "-- Shape --" << endl;
}

Shape* Shape::add(Shape* p) { //Shape에 들어온 도형에 따라 달라짐.
	this->next = p;
	return p;
}
