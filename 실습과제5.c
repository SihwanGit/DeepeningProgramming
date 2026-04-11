#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define stu 10 //학생 수

typedef struct _student {
	char name[20]; //이름
	char id[11]; //학번
	double grade; //평균평점
	char department[20]; //학과
	char course[20]; //진로
}STU;

void input_student(STU std[stu]);
void output_student(STU std[stu]);

int main() {
	STU std[stu];
	input_student(std);
	output_student(std);
	return 0;
}

//학생들의 정보를 입력하는 함수
void input_student(STU std[stu]) { //STU형 구조체 배열 std[stu]를 매개변수로 가진다.
	for (int i = 0; i < stu; i++) {
		printf("학생 %d의 정보를 입력해주세요: \n", i+1);
		printf("이름: "); //이름 입력
		scanf("%s", &std[i].name);
		printf("학번: "); //학번 입력
		scanf("%s", &std[i].id);
		printf("평균평점: "); //평군평점 입력
		scanf("%lf", &std[i].grade);
		printf("학과: "); //학과 입력
		scanf("%s", &std[i].department);
		printf("진로: "); //진로 입력
		scanf("%s", &std[i].course);
		printf("\n");
	}
} //void형이므로 반환값은 없다.

//학생들의 정보를 출력하는 함수
void output_student(STU std[stu]) { //STU형 구조체 배열 std[stu]를 매개변수로 가진다.
	for (int i = 0; i < stu; i++) {
		printf("학생%d의 정보: \n", i + 1);
		printf("이름: %s\n", std[i].name); //이름 출력
		printf("학번: %s\n", std[i].id); //학번 출력
		printf("평균평점: %.2lf\n", std[i].grade); //평균평점 출력
		printf("학과: %s\n", std[i].department); //학과 출력
		printf("진로: %s\n", std[i].course); //진로 출력
		printf("\n");
	}
} //void형이므로 반환값은 없다.