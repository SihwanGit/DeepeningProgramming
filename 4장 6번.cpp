#include<iostream>
#include<string>
using namespace std;

int main() {
	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다)" << endl << ">>";
	string str;
	getline(cin, str);
	while (1) {
		if (str == "exit") break; //str이 exit면 종료
		for (int i = str.length() - 1; i >= 0; i--) { //배열을 이용해 역순으로 출력
			cout << str[i];
		}
		cout << endl << endl  << ">>";
		getline(cin, str);
	}
	return 0;
}