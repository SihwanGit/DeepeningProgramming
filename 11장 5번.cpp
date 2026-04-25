#include<iostream>
#include<string>
using namespace std;

int main() {

	string cmd;
	cout << "getline(cin, string str)로 문자열을 읽습니다." << endl;
	while (1) {
		cout << "종료하려면 exit을 입력하세요 >> ";
		getline(cin, cmd);
		if (cmd == "exit") {
			cout << "프로그램을 종료합니다....." << endl;
			return 0;
		}
		else {
			cin.ignore(1);
		}
	}
	return 0;
}