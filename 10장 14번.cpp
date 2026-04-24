#include<iostream>
#include<map>
using namespace std;

int main() {
	map<string, string> code;
	string name, password;
	int check = 0;
	while (check != 1) {
		int c;
		cout << "입력:1, 조회:2, 종료:3 >> ";
		cin >> c;
		switch (c) {
		case 1:
			cout << "이름과 암호 >> ";
			cin >> name >> password;
			code[name] = password; //(이름, 암호) 저장
			cout << endl;
			break;
		case 2:
			cout << "이름? ";
			cin >> name;
			while (1) {
				cout << "암호? ";
				cin >> password;
				if (password != code[name]) cout << "실패~ " << endl;
				else {
					cout << "통과!!" << endl;
					break; //통과해야만 탈출
				}
			}
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