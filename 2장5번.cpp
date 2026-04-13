#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char n[100];
	cout << "문자들을 입력하라(100개 미만).\n";
	cin.getline(n, 100, '\n');
	int count = 0;
	for (int i = 0; i < strlen(n); i++) { //문자열의 길이만큼 반복
		if (n[i] == 120) { //n[i] == x면 개수 +1
			count++;
		}
	}
	cout << "x의 개수는 " << count;

	return 0;
}