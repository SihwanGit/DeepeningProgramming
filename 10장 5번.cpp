#include<iostream>
using namespace std;

template <class T>
T* concat(T a[], int sizea, T b[], int sizeb) {
	int sizec = sizea + sizeb;
	T* c = new T[sizec];
	for (int i = 0; i < sizec; i++) {
		if (i < sizea) {
			c[i] = a[i];
		}
		else if (i >= sizea && i < sizec) {
			c[i] = b[i - sizea];
		}
	}
	return c;
}

int main() {
	double x[5] = {1, 2, 3, 4, 5};
	double y[5] = { 6, 7, 8, 9, 0 };
	double *z = concat(x, 5, y, 5);
	for (int i = 0; i < 10; i++) {
		cout << z[i] << ' ';
	}
	cout << endl;
	delete [] z;

	return 0;
}