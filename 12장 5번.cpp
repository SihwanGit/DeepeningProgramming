#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {

	ifstream fin("12장 4번.cpp");
	if (!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	ofstream fout("12장 5번 소스코드.cpp");
	if (!fout) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	char ch;
	while ((ch = fin.get()) != EOF) { //모든 단어를 읽는다.
		if ((char)ch == '/') { //만약 /을 만나면
			fout << endl; //endl을 한번 넣어주고
			fin.ignore(100, '\n'); //그 문장이 끝날떄까지 입력을 무시한다.
		}
		else {
			fout << (char)ch;
		}
	}
	cout << "12장 4번.cpp를 12장 5번 소스코드.cpp에 복사했습니다." << endl;
	//12장 5번 소스코드.cpp에 12장 4번이 주석을 제외하고 복사되었음을 알 수 있다.

	fin.close();
	fout.close();
	return 0;
}