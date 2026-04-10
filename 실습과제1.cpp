#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand((unsigned)time(NULL)); //seed설정
	int com, player;  //player는 사람, com은 컴퓨터
	printf("가위(0), 바위(1), 보(2) 중 하나를 숫자로 입력해주시오: ");
	scanf_s("%d", &player);

	while ((player>2)||(player<0)) { //다른 숫자를 입력하면 다시 입력.
		printf("다시 입력해주시오: ");
		scanf_s("%d", &player);
	}

	com = rand()%3;
	if (player == com) {//서로 같으면 무승부
		printf("무승부\n");
	}
	else if ((player == com+1)||((player==0)&&(com==2))) {//플레이어 승리
		printf("플레이어 승리\n");
	}
	else {
		printf("컴퓨터 승리\n");//컴퓨터 승리
	}

	return 0;
}