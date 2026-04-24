#include<iostream>
#include<map>
using namespace std;

int main() {
	map<string, int> score;
	int grade;
	string name;

	cout << "***** 점수관리 프로그램 HIGH SCORE을 시작합니다 *****" << endl;
	int check = 0;
	while (check != 1) {
		int c;
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> c;
		switch (c) {
		case 1:
			cout << "이름과 점수 >> "; //이름과 점수 입력
			cin >> name >> grade;
			score[name] = grade; //("이름", 점수) 저장
			cout << endl;
			break;
		case 2:
			cout << "이름>> ";
			cin >> name;
			if (score[name] == 0) cout << name << "은 리스트에 없습니다." << endl; //없는걸 입력하면 0 반환
			else cout << name << "의 점수는 " << score[name] << endl;
			cout << endl;
			break;
		case 3:
			check = 1;
			break;
		default:
			cout << "다시 입력하세요" << endl << endl;
			break;
		}
	}
	cout << "프로그램을 종료합니다..." << endl;
	return 0;
}