#include<iostream>
#include<fstream>
using namespace std;

int main() {

	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	ofstream fout("c:\\temp\\system.txt");
	if (!fout) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	int ch;
	while ((ch = fin.get()) != EOF) {
		if ((char)ch >= 'a' && (char)ch <= 'z') { //A는 65, a는 97
			fout << (char)(ch - 32); //소문자를 대문자 변환
		}
		else {
			fout << (char)ch;
		}
	}
	cout << "복사가 완료되었습니다." << endl;

	fin.close();
	fout.close();
	return 0;
}