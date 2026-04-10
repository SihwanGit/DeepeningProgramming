#include<stdio.h>
int trycount();


int main() {
	int n;
	printf("n을 입력하시오: ");
	scanf_s("%d", &n); //호출하고 싶은 횟수 입력
	for (int i = 0; i < n; i++) { 
		printf("%d번쨰 호출\n", trycount()); //호출 횟수 n만큼 반복
	}

	return 0;
}


//함수의 반환이 끝난 이후에도 횟수가 유지되어야 하므로 정적 변수를 사용한다. 
int trycount() { //호출된 횟수를 반환하는 함수, 매개변수는 없다.
	static int count = 0;
	count++; //호출 횟수. 호출될 때마다 +1씩. 
	return count; //호출 횟수 반환
}