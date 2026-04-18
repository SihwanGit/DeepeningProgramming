#include<iostream>
using namespace std;

int add(int a[], int size = 5);
int add(int a[], int b[], int size=5);

int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6,7,8,9,10 };
	int c = add(a); //add(a, 5)
	int d = add(a, b); //add(a, b, 5)
	cout << c << endl;
	cout << d << endl;
	return 0;
}

//배열 a와 a의 size를 매개변수로 가져와 a배열의 모든 원소의 합을 구하는 함수
int add(int a[], int size) { //원형에서 디폴트 매개변수를 설정했으면 구현부에서는 설정하면 안됨.
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	return sum; //합 리턴
}

//배열 a와 b, 이들의 size를 매개변수로 가져와 a,b 배열의 모든 원소의 합을 구하는 함수
int add(int a[], int b[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i] + b[i];
	}
	return sum; //합 리턴
}