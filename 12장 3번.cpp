#include<iostream>
#include<fstream>
using namespace std;

int main() {

	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	int ch;
	while ((ch = fin.get()) != EOF) {
		if ((char)ch >= 'a' && (char)ch <= 'z') { //A는 65, a는 97
			cout << (char)(ch - 32); //소문자를 대문자 변환
		}
		else {
			cout << (char)ch;
		}
	}
	cout << endl;

	fin.close();
	return 0;
}