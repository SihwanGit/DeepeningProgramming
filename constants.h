#pragma once

#include <string>
using namespace std;

enum Action { // 더 뽑을지 말지
	HIT,
	STAND,
};

enum Shape { //문양
	SPADE,
	HEART,
	DIAMOND,
	CLOVER
};

class Card { //카드 = 문양 + 값
private:
	Shape shape;
	int value;

public:
	Card() { }

	Card(Shape shape, int value) {
		this->shape = shape;
		this->value = value;
	}

	Shape getShape() {
		return shape;
	}
	int getValue() {
		return value;
	}
};