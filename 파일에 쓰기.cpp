#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;

	cout << "이름 >> ";
	cin >> name;
	cout << "학번(숫자로) >> ";
	cin >> sid;
	cout << "학과 >> ";
	cin >> dept;

	ofstream fout("c::\\temp\\student.txt"); //파일 이름과 같아야하며 파일은 프로젝트 파일 안에 있어야한다.
	if (!fout) {
		cout << "c::\\temp\\student.txt 파일을 열 수 없다." << endl;
		return 0;
	}

	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();

	return 0;
}