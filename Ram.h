#pragma once

#include<iostream>
using namespace std;

class Ram {
private:
	char mem[100 * 1024]; //100KB ¸Þ¸ð¸®
	int size;
public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);
};