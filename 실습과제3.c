#include<stdio.h>
#include<math.h>

//복소수 구조체
typedef struct Complex_number {
	double real; //실수부
	double ima; // 허수부
}CS;

void Complex_Op(CS x, CS y);

int main() {
	CS x, y;
	printf("두 복소수의 실수부를 입력하시오: "); //실수부 입력
	scanf_s("%lf %lf", &x.real, &y.real);
	printf("두 복소수의 허수부를 입력하시오: "); //허수부 입력
	scanf_s("%lf %lf", &x.ima, &y.ima);
	printf("\n");
	Complex_Op(x, y);

	return 0;
}

//복소수의 연산을 출력하는 함수
void Complex_Op(CS x, CS y) {
	//두 복소수 x와 y를 매개변수로 사용한다.
	double mut_real = (x.real * y.real) - (x.ima * y.ima); //실수부 곱
	double mut_ima = (x.real * y.ima) + (x.ima * y.real); //허수부 곱

	printf("복소수 x: %.2lf + %.2lfi\n", x.real, x.ima); //복소수 x
	printf("복소수 y: %.2lf + %.2lfi\n", y.real, y.ima); //복소수 y
	printf("x + y: %.1lf + %.1lfi\n", x.real + y.real, x.ima + y.ima); //합
	printf("x - y: % .1lf + % .1lfi\n", x.real - y.real, x.ima - y.ima); //x-y의 차
	printf("y - x: %.1lf + %.1lfi\n", y.real - x.real, y.ima - x.ima); //y-x의 차
	printf("x * y: %.1lf + %.1lfi\n", mut_real, mut_ima); //곱
	printf("|x|: %.1lf\n", sqrt((x.real * x.real) + (x.ima * x.ima))); //x의 절대값
	printf("|y|: %.1lf\n", sqrt((y.real * y.real) + (y.ima * y.ima))); // y의 절대값
} //void형이므로 반환값은 없다.