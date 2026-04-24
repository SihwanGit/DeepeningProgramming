#include<iostream>
using namespace std;

template<class T>
void reverseArray(T x[], int size) {
	T* y = new T[size];
	for (int i = 0; i < size; i++) {  //y에다가 역순으로 집어넣기
		y[i] = x[size - 1 - i];
	}
	for (int i = 0; i < size; i++) { //x에다 y넣기
		x[i] = y[i];
	}
	delete[] y;
}

int main() {
	int x[] = {1, 10, 100, 5, 4};
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++) cout << x[i] << ' ';
	cout << endl;

	return 0;
}