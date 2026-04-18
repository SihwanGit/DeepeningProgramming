#include<iostream>
using namespace std;

int add(int p[], int pn);
int add(int a[], int an, int b[], int bn);

//동적할당을 사용해 a와 b의 크기, 원소를 직접 입력한 뒤 두 배열의 원소를 더하는 프로그램을 구현하겠다.

int main() {
	int an, bn;
	cout << "배열 a의 크기를 입력하세요 >> ";
	cin >> an;
	int* a = new int[an]; //a의 크기만큼 동적할당
	cout << "배열 a의 원소들을 입력하세요 >> ";
	for (int i = 0; i < an; i++)
		cin >> a[i]; //a의 원소입력

	cout << endl << "배열 b의 크기를 입력하세요 >> ";
	cin >> bn;
	int* b = new int[bn]; //b의 크기만큼 동적할당
	cout << "배열 b의 원소들을 입력하세요 >> ";
	for (int i = 0; i < bn; i++)
		cin >> b[i]; //b의 원소 입력

	cout << endl;
	int c = add(a, an);
	int d = add(b, bn);
	int e = add(a, an, b, bn);
	cout << "배열 a의 원소들의 합 >> " << c << endl;
	cout << "배열 b의 원소들의 합 >> " << d << endl;
	cout << "배열 a,b의 모든 원소들의 합 >> " << e << endl;
	return 0;

	delete[] a;
	delete[] b;
}

//배열과 배열의 크기를 매개변수로 받아와 모든 원소들의 합을 리턴하는 함수
int add(int p[], int pn) {
	int sum = 0;
	for (int i = 0; i < pn; i++)
		sum += p[i];
	return sum;
}

//두 배열과 각각의 크기를 매개변수로 받아와 모든 원소들의 합을 리턴하는 함수
int add(int a[], int an, int b[], int bn) {
	int sum = 0;
	for (int i = 0; i < an; i++)
		sum += a[i];
	for (int i = 0; i < bn; i++)
		sum += b[i];
	return sum;
}