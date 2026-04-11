#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define pro 5 //교수 수
int num[pro]; //담당과목 수

typedef struct person { //개인정보
	char name[20]; //이름
	char phone[12]; //전화번호
	char adress[30]; //주소
}PER;

typedef struct professor {//교수 정보
	PER per; //개인정보
	char subject[5][20]; //담당과목
	char department[20]; //학과
} PRO;

void input_professor(PRO pf[pro]);
void output_professor(PRO pf[pro]);

int main() {
	PRO pf[5];
	input_professor(pf);
	output_professor(pf);

	return 0;
}

//교수의 정보를 입력하는 함수
void input_professor(PRO pf[pro]) { //PRO형 구조체 배열 pf[pro]을 매개변수로 가진다.
	for (int i = 0; i < pro; i++) {
		printf("교수 %d의 정보를 입력해주세요: \n", i + 1);
		printf("이름: "); //이름 입력
		scanf("%s", &pf[i].per.name);
		printf("전화번호: "); //전화번호 입력
		scanf("%s", &pf[i].per.phone);
		printf("주소: "); //주소 입력
		scanf("%s", &pf[i].per.adress);
		printf("담당과목의 수를 입력해주세요: ");
		scanf("%d", &num[i]);
		printf("담당과목: ");
		for (int j = 0; j < num[i]; j++) { //담당 과목의 수만큼 입력
			scanf("%s", &pf[i].subject[j]);
		}
		printf("학과: ");
		scanf("%s", &pf[i].department);
		printf("\n");
	}
}

//교수의 정보를 출력하는 함수
void output_professor(PRO pf[pro]) { //PRO형 구조체 배열 pf[pro]을 매개변수로 가진다.
	for (int i = 0; i < pro; i++) {
		printf("교수 %d의 정보: \n", i + 1);
		printf("이름: %s\n", pf[i].per.name); //이름 출력
		printf("전화번호: %s\n", pf[i].per.phone); //전화번호 출력
		printf("주소: %s\n", pf[i].per.adress); //주소 출력
		printf("담당과목: ");
		for (int j = 0; j < num[i]; j++) {
			printf("%s ", pf[i].subject[j]); //담당과목의 개수만큼 출력
		}
		printf("\n");
		printf("학과: %s\n", pf[i].department); //학과 출력
		printf("\n");
	}
} //void형이므로 반환값은 없다.