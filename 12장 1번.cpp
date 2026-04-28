#include<iostream>
#include<fstream>
using namespace std;

int main() {

	ifstream fin("c:\\temp\\test.txt");
	if (!fin) {
		cout << "파일 열기에 실패했습니다." << endl;
		return 0;
	}

	int ch;
	while ((ch = fin.get()) != EOF) {
		cout << (char)ch;
	}
	cout << endl;

	fin.close();
	return 0;
}