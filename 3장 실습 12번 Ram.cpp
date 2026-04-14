#include"Ram.h"

Ram::Ram() {
	mem[0] = { 0 };
	size = 100 * 1024;
}

Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}

char Ram::read(int address) { //메모리 번지의 값 반환
	return mem[address];
}

void Ram::write(int adress, char value) { //주소를 받아 해당 주소에 값 저장
	mem[adress] = value;
}