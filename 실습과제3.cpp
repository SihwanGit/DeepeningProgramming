#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int number; //전역변수
static int max = 32 + rand()%32;
static int min = 32 + rand()%32; 
//정적 외부변수 max, min

void setNumber();
void printAnswer(int user);
void printHigher();
void printLower();
void printHead(int user);


int main() {
	int  user = 0; //사용자가 입력하는 변수.
	srand((unsigned)time(NULL));
	setNumber();
	printHead(user);
	return 0;
}


//number에 난수 할당
void setNumber() { //매개변수는 없다.
	number = 1 + rand() % 100;
} //void형이므로 반환값은 없다.


//실행횟수를 출력하고, 정답 여부를 알려주는 함수
void printAnswer(int user) { //입력값, user를 매개변수로 가진다.
	static int trycount = 0; //시도한 횟수 trycount
	trycount++;
	printf("\n<%d번째 시도>\n", trycount); //시도 횟수 출력

	if (user == number) {
		printf("정답입니다.\n"); //맞으면 정답
	}
	else {
		printf("오답입니다.\n"); //틀리면 오답. 다시 입력
	}
} //void형이므로 반환값은 없다.

//number의 최댓값을 알려주는 함수
void printHigher() { //매개변수는 없다.
	if (max + number > 100) {
		printf("number는 100보다 작다\n");
	}
	else {
		printf("number는 %d보다 작다.\n", max + number);
		//number < number + max를 이용해 number의 최댓값을 알려준다.
	}
	max /= 2; //max의 범위를 점점 좁히면서 
} //void형이므로 반환값은 없다


//number의 최솟값을 알려주는 함수
void printLower() { //매개변수는 없다.
	if (number - min < 0) {
		printf("number는 0보다 크다\n");
	}
	else {
		printf("number는 %d보다 크다.\n", number - min);
		//number > number - min을 이용해 number의 최솟값을 알려준다.
	}
	min /= 2; //min의 범위를 점점 좁힌다.
} //void형이므로 반환값은 없다.


//답을 입력하는 문구를 띄우는 함수
void printHead(int user) {//입력값, user를 매개변수로 가진다.
	printf("답을 입력하시오: ");
	scanf_s("%d", &user);
	printAnswer(user);
	while (user != number) { //맞을 때까지 반복
		printLower();
		printHigher();
		printf("다시 입력하시오: ");
		scanf_s("%d", &user);
		printAnswer(user);
	}
} //void형이므로 반환값은 없다.