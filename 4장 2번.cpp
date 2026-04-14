#include<iostream>
using namespace std;
#define Num 5 //입력할 정수의 개수

//동적할당을 할 때는 메모리가 부족한지 아닌지 확인하는 코드가 필요하다. 수정

int main() {
	int* p = new int[Num];
	if (!p) {
		printf("메모리를 할당할 수 없습니다.");
		return 0;
	}
	cout << "정수 " << Num << "개 입력>> ";
	for (int i = 0; i < Num; i++) {
		cin >> p[i]; //5개의 정수 입력
	}

	int sum = 0;
	for (int i = 0; i < Num; i++) { //입력한 수들의 합
		sum += p[i];
	}

	double ave = (double)sum / Num; //실수형 평균
	cout << "평균 " << ave << endl;

	delete[] p;
	return 0;
}