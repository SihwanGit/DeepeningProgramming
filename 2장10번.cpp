#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char str[100];
	cout << "문자열 입력>>";
	cin.getline(str, 100); //문자열 입력
	for (int i = 0; i < strlen(str); i++) { //이중배열을 사용해 차례대로 출력
		for (int j = 0; j < i+1; j++) {
			cout << str[j];
		}
		cout << '\n';
	}

	return 0;
}