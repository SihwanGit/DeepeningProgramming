#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define stu 10 //학생 수
int num[stu]; //지도교수의 담당과목 수

typedef struct person { //개인정보
	char name[20]; //이름
	char phone[12]; //전화번호
	char adress[30]; //주소
}PER;

typedef struct professor {//지도교수 정보
	PER per; //지도교수의 개인정보
	char subject[5][20]; //담당과목
	char department[20]; //학과
} PRO;

typedef struct student {
	PER per;
	char id[11]; //학번
	double grade; //평균학점
	char department[20]; //학과
	char course[20]; //진로
	PRO pro;
} STD;

void input_student(STD st[stu]);
void output_student(STD st[stu]);

int main() {
	STD st[10];
	input_student(st);
	output_student(st);

	return 0;
}

//학생의 정보를 입력하는 함수
void input_student(STD st[stu]) { //STD형 구조체 배열 st[stu] 매개변수로 가진다.
	for (int i = 0; i < stu; i++) {
		printf("학생 %d의 정보를 입력해주세요 : \n", i + 1);
		printf("이름: "); //학생 이름
		scanf("%s", &st[i].per.name);
		printf("전화번호: "); //학생 전화번호
		scanf("%s", &st[i].per.phone);
		printf("주소: "); //학생 주소
		scanf("%s", &st[i].per.adress);
		printf("학번: "); //학번
		scanf("%s", &st[i].id);
		printf("평균평점: "); //평균 평점
		scanf("%lf", &st[i].grade);
		printf("학과: "); //학과
		scanf("%s", &st[i].department);
		printf("진로: "); //진로
		scanf("%s", &st[i].course);
		printf("지도 교수 이름: "); //지도 교수 이름 입력
		scanf("%s", &st[i].pro.per.name);
		printf("지도 교수 전화번호: "); //지도 교수 전화번호 입력
		scanf("%s", &st[i].pro.per.phone);
		printf("지도 교수 주소: "); //지도 교수 주소 입력
		scanf("%s", &st[i].pro.per.adress);
		printf("\n");
	}
} //void형이므로 반환값은 없다.

//학생의 정보를 출력하는 함수
void output_student(STD st[stu]) { //STD형 구조체 배열 st[stu] 매개변수로 가진다.
	for (int i = 0; i < stu; i++) {
		printf("학생 %d의 정보: \n", i + 1);
		printf("이름: %s\n", st[i].per.name); //학생 이름
		printf("전화번호: %s\n", st[i].per.phone); //학생 전화번호
		printf("주소: %s\n", st[i].per.adress); //학생 주소
		printf("학번: %s\n", st[i].id); //학번
		printf("평균평점: %.1lf\n", st[i].grade); //평균 평점
		printf("학과: %s\n", st[i].department); //학과
		printf("진로: %s\n", st[i].course); //진로
		printf("지도 교수 이름: %s\n", st[i].per.name); //지도 교수 이름 출력
		printf("지도 교수 전화번호: %s\n", st[i].per.phone); //지도 교수 전화번호 출력
		printf("지도 교수 주소: %s\n", st[i].per.adress); //지도 교수 주소 출력
		printf("\n");
	}
} //void형이므로 반환값은 없다.