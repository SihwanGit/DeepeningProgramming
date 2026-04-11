#include<stdio.h>
#define SIZE 10

//최대값 요소를 찾아 그것의 주소를 반환하는 함수.
double* get_max(double *A, int size) { //배열의 크기 size와 배열 A를 매개변수로 사용한다.
	int max = 0;
	for (int i = 0; i < SIZE; i++) {
		if (A[i] > A[max]) { //최대값의 인덱스
			max = i; 
		}
	}
	return &A[max];
} //최대값의 주소. &A[max]를 반환

int main() {
	double array[SIZE];
	for (int i = 0; i < SIZE; i++) {
		printf("배열에 넣을 수를 입력하시오: ");  //배열에 숫자 입력
		scanf_s("%lf", &array[i]);
	}
	printf("\n");
	double* p = get_max(array, SIZE);
	printf("최대값은 = %.2lf이고, 해당 요소의 주소는 %p입니다.\n", *p, p);

	return 0;
}