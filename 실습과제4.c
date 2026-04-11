#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define per 2 //사람 수

typedef struct person { //개인정보
	char name[10]; //이름
	char phone[12]; //전화번호
	char adress[30]; //주소
}PER;

void input_person(PER p[per]);
void output_person(PER p[per]);

int main() {
	PER p[per];
	input_person(p);
	output_person(p);
	return 0;
}

//사람 정보를 입력하는 함수
void input_person(PER p[per]) { //PER형 구조체 배열 p[per]을 매개변수로 가진다.
	for (int i = 0; i < per; i++) {
		printf("사람 %d의 정보를 입력해주세요: \n", i + 1);
		printf("이름: "); //이름 입력
		scanf("%s", &p[i].name);
		printf("전화번호: "); //전화번호 입력
		scanf("%s", &p[i].phone);
		printf("주소: "); //주소 입력
		scanf("%s", &p[i].adress);
		printf("\n");
	}
}//void 형이므로 반환값은 없다.

//사람 정보를 출력하는 함수
void output_person(PER p[per]) { //PER형 구조체 배열 p[per]을 매개변수로 가진다.
	for (int i = 0; i < per; i++) {
		printf("사람 %d의 정보: \n", i + 1);
		printf("이름: %s\n", p[i].name); //이름 출력
		printf("전화번호: %s\n", p[i].phone); //전화번호 출력
		printf("주소: %s\n", p[i].adress); //주소 출력
		printf("\n");
	}
}//void형이므로 반환값은 없다.