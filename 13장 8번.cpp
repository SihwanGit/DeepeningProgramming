#include <iostream> 
using namespace std;
int* copy(int* src, int size) { //retSize는 필요없다.
	int* p = NULL;
	if (size < 0) {
		throw -1; // too small
	}
	else if (size > 100) {
		throw -2; // too big
	}
	p = new int[size]; //메모리 할당
	if (p == NULL) {
		throw -3; // memory short
	}
	else if (src == NULL) {
		delete[] p;
		throw -4; // NULL source
	}
	else { // 정상적으로 배열을 복사하는 부분
		for (int n = 0; n < size; n++) p[n] = src[n];
		return p;
	}
}

int main() {
	try {
		int x[] = { 1,2,3 };
		int* p = copy(x, 3);
		for (int i = 0; i < 3; i++) cout << p[i] << ' ';
		cout << endl;
		delete[] p;
	}
	catch (int n) {
		if (n == -1) {
			cout << "프로그램 오류 : 크기가 너무 작습니다." << endl;
		}
		else if (n == -2) {
			cout << "프로그램 오류 : 크기가 너무 큽니다." << endl;
		}
		else if (n == -3) {
			cout << "프로그램 오류 : 메모리가 부족합니다." << endl;
		}
		else if (n == -4) {
			cout << "프로그램 오류 : 원소 중 NULL이 있습니다." << endl;
		}
	}
	return 0;
}