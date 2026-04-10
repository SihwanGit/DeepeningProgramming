#include<stdio.h>
#define Raw 2 //행의 개수
#define Col 3 //열의 개수

void matrix_sum(double(*px)[Col], double(*py)[Col], double(*pxy)[Col]);
void matrix_sub(double(*px)[Col], double(*py)[Col], double(*pxy)[Col]);
void matrix_op(double(*px)[Col], double(*py)[Col], double(*pxy)[Col], char op);
void print_array(double(*pi)[Col]);

int main() {
	double x[Raw][Col] = {
	{4.2, 4.3, 3.8},
	{3.7, 1.5, 0.7}};

	double y[Raw][Col] = {
	{5.2, 2.1, 1.8},
	{3.2, 1.4, 2.9}};

	double(*px)[Col], (*py)[Col], (*pxy)[Col], xy[Raw][Col] = { 0 };
	char op;
	px = x;
	py = y;
	pxy = xy;
	printf("연산자를 입력해 주세요(+ or -): ");
	scanf_s("%c", &op, sizeof(op));
	print_array(px);
	(op == '+') ? printf("+\n") : printf("-\n");
	print_array(py);
	printf("=\n");
	matrix_op(px, py, pxy, op);
	print_array(pxy);

	return 0;
}

//행렬을 더하는 함수
void matrix_sum(double(*px)[Col], double(*py)[Col], double(*pxy)[Col]) {
//두 이차원배열을 가리키는 배열포인터px,py와 연산값을 넣을 이차원배열을 가리키는 pxy포인터를 매개변수로 가진다.
	for (int i = 0; i < Raw; i++) {
		for (int j = 0; j < Col; j++) {
			*(*(pxy + i) + j) = *(*(px + i) + j) + *(*(py + i) + j);
		}
	}
} //void 형이므로 반환값은 없다.

//행렬끼리 뺴는 함수
void matrix_sub(double(*px)[Col], double(*py)[Col], double(*pxy)[Col]) {
//두 이차원배열을 가리키는 배열포인터px,py와 연산값을 넣을 이차원배열을 가리키는 pxy포인터를 매개변수로 가진다.
	for (int i = 0; i < Raw; i++) {
		for (int j = 0; j < Col; j++) {
			*(*(pxy + i) + j) = *(*(px + i) + j) - *(*(py + i) + j);
		}
	}
} //void 형이므로 반환값은 없다.

void matrix_op(double(*px)[Col], double(*py)[Col], double(*pxy)[Col], char op) {
	//두 이차원배열을 가리키는 배열포인터px,py와 연산값을 넣을 이차원배열을 가리키는 pxy포인터, 
	//연산자를 인수로 받아올 char형 op를 매개변수로 가진다.

	if (op == '+') { //만약 op가 +라면 두 이차원배열의 원소들을 더한다.
		matrix_sum(px, py, pxy);
	}
	else if (op == '-') { //만약 op가 -면 x-y를 실행하라.
		matrix_sub(px, py, pxy);
	}
	else {
		printf("잘못된 입력\n");
	}

} //void형이므로 반환값은 없다.

//이차원배열의 값을 printf해주는 함수
void print_array(double(*pi)[Col]) { //츨력하고자 하는 이차원배열을 가리키는 pi포인터를 매개변수로 가진다.
	for (int i = 0; i < Raw; i++) {
		for (int j = 0; j < Col; j++) {
			printf("%.1f ", *(*(pi + i) + j)); //이차원배열의 i행j열을 출력
		}
		printf("\n"); //i행을 다 출력하면 \n하고 그 다음 행을 출력
	}
} //void형이므로 반환값은 없다.