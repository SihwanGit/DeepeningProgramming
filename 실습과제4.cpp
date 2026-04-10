#include<stdio.h>

void print_data(int* x, int len);
void N_plus(int* x, int len, int n);

int main() {
	int* pdata, n, data[] = { 3, 21, 35, 57, 24, 82, 8 };
	int len = sizeof(data) / sizeof(data[0]); //배열 data의 길이 
	pdata = data; //pointer 초기화 
	print_data(pdata, len); //n을 더하기 전 배열 원소의 값 출력 
	printf("증가시키고 싶은 수를 입력하시오 : ");
	scanf_s("%d", &n); //더하고 싶은 수 n입력
	N_plus(pdata, len, n); //배열의 원소에 n을 더한다. 
	print_data(pdata, len);	//n이 더해진 이후의 값을 출력 

	return 0;
}

//배열의 원소들의 값을 출력해주는 함수
void print_data(int* x, int len) { //배열 data를 가리키는 포인터 x, 배열의 길이 len을 매개변수로 가진다.
	for (int i = 0; i < len; i++) { //배열의 길이만큼 반복 
		printf("%d ", *(x + i));
	}
	printf("\n"); //배열의 원소 출력
} //void형이므로 반환값은 없다.


//배열의 원소에 n을 더하는 함수 
void N_plus(int* x, int len, int n) { //배열 data를 가리키는 포인터 x, 배열의 길이 len, 더하고 싶은 숫자 n을 매개변수로 가진다.

	for (int i = 0; i < len; i++) { //배열의 길이만큼 반복 
		*(x + i) = *(x + i) + n;
	}
}//void형이므로 반환값은 없다.