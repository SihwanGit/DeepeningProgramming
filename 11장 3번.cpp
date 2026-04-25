#include<iostream>
#include<cstring>
using namespace std;

int main() {
	cout << "영어문장;한글문장 형식으로 입력해주세요 >> ";
	char ch;
	cin.ignore(100, ';'); //99개의 철자가 입력된다고 가정할 때 ;를 만날 때까지 지우기
	
	while ((ch = cin.get()) != EOF) {
		cout << (char)ch; //출력하면 버퍼에서 빠지는 거임.
		if (ch == '\n') {
			cout << "영어문장;한글문장 형식으로 입력해주세요 >> ";
			cin.ignore(100, ';'); //ignore()는 ignore()함수 사용 이후 제한자를 만날 때까지 buf에서 삭제.
		}
	}

	return 0;
}