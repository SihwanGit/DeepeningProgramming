#include<iostream>
using namespace std;

class MyVector {
private:
	int* mem;
	int size;
public:
	MyVector() : MyVector(100, 0) {} //위임 생성자
	MyVector(int n, int val);
	~MyVector() { delete mem; }
	void print_Mem();
};

MyVector::MyVector(int n, int val) {
	size = n;
	mem = new int[size];
	for (int i = 0; i < size; i++) mem[i] = val;
}

void MyVector::print_Mem() {
	for (int i = 0; i < size; i++) {
		cout << mem[i];
	}
	cout << endl;
}

int main() {
	int n, va;
	cout << "배열의 크기와 값을 입력하세요 >> ";
	cin >> n >> va;
	MyVector m1, m2(n, va);
	m1.print_Mem();
	m2.print_Mem();

	return 0;
}