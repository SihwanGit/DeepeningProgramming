#include<stdio.h>
#define SIZE 5
void copyarray(double* source, double* target, int size);
void print_ary(double* pray, int size);

int main() {
	double target[5], ary[5] = { 3.12, 5.14, 7.25, 7.48, 5.91 };
	double* psource, * ptarget;
	psource = ary; 
	ptarget = target;

	copyarray(ary, ptarget, SIZE);
	print_ary(ptarget, SIZE);

	return 0;
}

//source를 target에 복사하는 함수 만들기.
void copyarray(double* source, double* target, int size) {
	//각각 원본과 복사본을 가리키는 포인터 source와 target, 복사하고자하는 크기인 size를 매개변수로 가진다.
	for (int i = 0; i < size; i++) {
		*(target + i) = *(source + i);
	}
} //void형이므로 반환값은 없다.

//배열의 원소들을 출력해주는 함수 만들기
void print_ary(double* pary, int size) {
	//출력하고자하는 배열을 가리키는 포인터 pary와 배열의 크기 size를 매개변수로 가진다.
	for (int i = 0; i < size; i++) {
		printf("%.2f ", *(pary + i));
	}
	printf("\n");
} //void형이므로 반환값은 없다.