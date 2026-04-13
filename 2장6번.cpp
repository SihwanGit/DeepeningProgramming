#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char pw[20], pw2[20];
	cout << "새 암호를 입력하세요>>";
	cin >> pw;
	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> pw2;
	if (strcmp(pw, pw2) == 0) cout << "같습니다."; //두 암호 비교 후 같으면 "같다" 출력
	else cout << "같지 않습니다."; //다르면 "같지 않다" 출력

	return 0;
}