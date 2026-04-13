#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int n, price = 0; //n은 잔 수, price는 가격 총합
	char coffee[100]; //커피 종류 입력
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다."<< endl;
	while (price < 20000) {
		cout << "주문>> ";
		cin >> coffee >> n;
		if (strcmp(coffee, "에스프레소") == 0) {
			cout << n * 2000 << "원입니다. 맛있게 드세요.\n";
			price += n * 2000;
		}
		else if(strcmp(coffee, "아메리카노") == 0) {
			cout << n * 2300 << "원입니다. 맛있게 드세요.\n";
			price += n * 2300;
		}
		else if (strcmp(coffee, "카푸치노") == 0) {
			cout << n * 2500 << "원입니다. 맛있게 드세요.\n";
			price += n * 2500;
		}
	}
	cout << "오늘 " << price << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~\n";

	return 0;
}