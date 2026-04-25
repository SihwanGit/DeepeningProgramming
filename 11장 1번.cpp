#include<iostream>
using namespace std;

int main() {
	cout << "문자열을 입력해주세요 >> ";
	int ch, count = 0;
	while ((ch = cin.get()) != EOF) {
		if (ch == 'a') count++;
		if (ch == '\n') break;
	}
	cout << 'a' << "의 개수는 " << count << "개" << endl;
	return 0;
}