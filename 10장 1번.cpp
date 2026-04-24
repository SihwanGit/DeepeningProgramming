#include<iostream>
using namespace std;

template <class T>
T biggest(T a[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (a[max] < a[i]) max = i;
	}
	return a[max];
}

int main() {
	int x[] = {1, 10, 100, 5, 4};
	int max = biggest(x, 5);
	cout << max << endl;

	return 0;
}