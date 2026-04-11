#include<stdio.h>
#define STU 10 //학생들의 수
void input_grades(double grades[STU]);
void exchange(double grades[STU], double scores[STU]);

int main() {
	double grades[STU] = { 0 }, scores[STU] = { 0 };
	input_grades(grades, scores);
	printf("\n");
	exchange(grades, scores);	
	return 0;
}

//학생들의 점수를 입력하는 함수
void input_grades(double grades[STU]) {//점수가 입력할 배열 변수 grades를 매개변수로 가진다.
	printf("학생들의 학점을 입력해주시오(4.3점 만점)\n"); //학생들의 점수 입력
	for (int i = 0; i < STU; i++) {
		printf("학생%d의 학점: ", i + 1);
		scanf_s("%lf", &grades[i]);
		while ((grades[i] > 4.3) || (grades[i] < 0)) { //잘못 입력하면 다시 입력
			printf("다시 입력해주세요: ");
			scanf_s("%lf", &grades[i]);
		}
	}
}//void 형이므로 반환하는 값은 없다.

//4.3점 만점을 100점 만점으로 환산하는 함수
void exchange(double grades[STU], double scores[STU]) {
//점수가 저장된 grades와 100점으로 환산할 배열 scores를 매개변수로 가진다.
	for (int i = 0; i < STU; i++) { //학생들의 점수 환산
		scores[i] = grades[i] / 4.3 * 100;
	}
	printf("점수\n");
	for (int i = 0; i < STU; i++) { //환산 점수 출력
		printf("학생%d의 점수: %.2f\n", i + 1, scores[i]);
	}
} //void형이므로 반환값은 없다.
