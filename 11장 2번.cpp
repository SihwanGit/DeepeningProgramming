#include<iostream>
using namespace std;

int main() {
	char buf;
	int count = 0;
	cout << "문자열을 입력하세요(최대 99자) >> ";
	while (1) {
		cin.get(buf);
		if (buf == ' ') count++;
		else if (buf == '\n') break;
	}
	cout << "공백문자 ' '의 개수는 " << count << "개 입니다." << endl;

	return 0;
}