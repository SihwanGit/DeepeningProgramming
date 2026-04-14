#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

int main() {
	string str;
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)" << endl;
	cout << ">> ";
	getline(cin, str);
	while (1) {
		if (str == "exit") break; //str이 exit면 종료
		srand((unsigned)time(NULL));
		int ranIndex = rand() % str.length();	//랜덤하게 바꿀 문자열의 인덱스
		int ranAlpha = rand() % 26;				//랜덤하게 바꿀 알파벳
		str[ranIndex] = (char)(ranAlpha + 97);	//str의 랜덤 인덱스를 랜덤한 알파벳으로 변경
		cout << str << endl << ">>";
		getline(cin, str);
	}

	return 0;
}