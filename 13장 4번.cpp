#include<iostream>
#include<fstream>
using namespace std;

int getFileSize(const char* file) {
	if (file == NULL) throw -1; //NULL이면 -1 던짐
	ifstream fin(file);
	if (!fin) throw -2; //파일을 못열면 -2 던짐
	fin.seekg(0, ios::end);
	int len = fin.tellg();
	return len;
}

int main() {
	int n = 0, m = 0;
	try { 
		n = getFileSize("c:\\windows\\system.ini");
		cout << "파일 크기 = " << n << endl;
	}
	catch (int n) { 
		if (n == -1) cout << "예외 발생 : 파일명이 NULL입니다." << endl;
		else if (n == -2) cout << "예외 발생 : 파일을 열 수 없습니다." << endl;
	}

	//catch가 실행되면 catch 밑의 문장을 실행함.
	//n과 m을 따로 검사하고 싶다면 try를 두번 사용해야함.
	//하나로 작성했다가 n에서 오류가 나면 m은 검사를 안한채 넘어가기 때문
	
	try {
		m = getFileSize(NULL);
		cout << "파일 크기 = " << m << endl;
	}
	catch (int n) {
		if (n == -1) cout << "예외 발생 : 파일명이 NULL입니다." << endl;
		else if (n == -2) cout << "예외 발생 : 파일을 열 수 없습니다." << endl;
	}

	return 0;
}