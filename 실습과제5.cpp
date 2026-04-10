#include<stdio.h>
void swap(int* x, int* y);


int main() {
	int x, y, * px, * py;
	px = &x; //포인터 초기화
	py = &y; //포인터 초기화
	printf("x와 y의값을 차례대로 입력하시오: ");
	scanf_s("%d %d", &x, &y); //x와 y 입력
	swap(px, py);
	printf("변경 이후의 값: x = %d, y = %d", x, y);

	return 0;
}


//변수의 값을 서로 바꿔주는 함수.
void swap(int* x, int* y) { //바꾸고자 하는 두 변수를 가리키는 포인터 x,y를 매개변수로 가진다.
	int temp;
	temp = *x;
	*x = *y;
	*y = temp; //x와 y의 값을 바꿈
} //void형이므로 반환값은 없다.
