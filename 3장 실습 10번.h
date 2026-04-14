#pragma once

#include<iostream>
using namespace std;

class Add { //더하기 선언부
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Sub { //빼기 선언부
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Mul { //곱하기 선언부
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};

class Div { //나누기 선언부
private:
	int a, b;
public:
	void setValue(int x, int y);
	int calculate();
};