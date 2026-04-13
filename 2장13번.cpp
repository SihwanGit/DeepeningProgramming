#include<iostream>
using namespace std;

int main() {
	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;
	int n, per;
	while (1) {
		cout << "짬뽕:1 짜장:2, 군만두: 3, 종료:4>> ";
		cin >> n;
		if (n == 1) { //짬뽕
			cout << "몇인분?";
			cin >> per;
			cout << "짬뽕 " << per << "인분 나왔습니다.\n";
		}
		else if (n == 2) { //짜장
			cout << "몇인분?";
			cin >> per;
			cout << "짜장 " << per << "인분 나왔습니다.\n";
		}
		else if (n == 3) { //군만두
			cout << "몇인분?";
			cin >> per;
			cout << "군만두 " << per << "인분 나왔습니다.\n";
		}
		else if (n == 4) { //종료
			cout << "오늘 영업은 끝났습니다.\n";
			break;
		}
		else { //잘못된 입력
			cout << "다시 주문하세요!!\n";
		}
	}

	return 0;
}