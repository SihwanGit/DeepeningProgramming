#include<iostream>
using namespace std;

class BaseMemory {
	char* mem;
protected:
	BaseMemory(int size) { mem = new char[size]; }
	BaseMemory(int size, char* x, int max_index); //burn을 위한 생성자
	~BaseMemory() { delete[] mem; } //메모리 반환
	char get(int index) { return mem[index]; } //read를 위한 맴버함수
	void set(int index, char item) { mem[index] = item; } //write를 위한 맴버함수
};

class Rom : public BaseMemory {
public:
	Rom(int size, char* x, int max_index) : BaseMemory(size, x, max_index) {} //burn
	char read(int index) { return get(index); }
};

class Ram : public BaseMemory {
public:
	Ram(int size) : BaseMemory(size) {}
	void write(int index, char item) { set(index, item); }
	char read(int index) { return get(index); }
};

BaseMemory::BaseMemory(int size, char* x, int max_index) { //mem[i] = x[i]를 해주는 생성자
	mem = new char[size];
	for (int i = 0; i < max_index; i++) {
		mem[i] = x[i];
	}
}

int main() {
	char x[5] = { 'h', 'e', 'l', 'l', 'o' };
	Rom biosROM(1024 * 10, x, 5);
	Ram mainMemory(1024 * 1024);

	for(int i = 0; i < 5; i++) mainMemory.write(i, biosROM.read(i));
	for (int i = 0; i < 5; i++) cout << mainMemory.read(i);
	cout << endl;

	return 0;
}