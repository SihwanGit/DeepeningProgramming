#include<stdio.h>
void mat_op(int(*xpary)[5]);
void print_array(int(*pary)[5]);

int main() {
	int ary[][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int(*pary)[5]; //배열포인터 생성
	pary = ary; 

	printf("연산 전\n");
	print_array(pary);
	mat_op(pary);
	printf("연산 후\n");
	print_array(pary);

	return 0;
}


//배열포인터를 사용해 이차원배열의 원소에 5를 더하는 함수.
void mat_op(int(*pary)[5]) { //이차원배열 가리키는 배열포인터 pary를 매개변수로 가진다.
	for (int i = 0; i < 2; i++) { //행만큼 반복
		for (int j = 0; j < 5; j++) { //열만큼 반복
			(*(*(pary + i) + j)) = (*(*(pary + i) + j)) + 5; //원소의 값에 5씩 더함.
		}
	}
} //void형이므로 반환값은 없다.


//이차원배열을 출력하는 함수
void print_array(int(*pary)[5]) { //출력하고자 하는 이차원배열 pary를 매개변수로 가진다.
	for (int i = 0; i < 2; i++) { //배열 출력
		for (int j = 0; j < 5; j++) {
			printf("%d ", *(*(pary + i) + j));
		}
		printf("\n");
	}
	printf("\n");
} //void형이므로 반환값은 없다.