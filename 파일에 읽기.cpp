#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char name[10], dept[20];
	int sid;

	ifstream fsrc("student.txt"); //fout는 ostream, fin은 istream
	if (!fsrc) {
		cout << "c::\\temp\\student.txt 파일을 열 수 없다." << endl;
		return 0;
	}

	fsrc >> name;
	fsrc >> dept; //순서 바꾸면 안들어감.
	fsrc >> sid;

	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;

	fsrc .close();

	return 0;
}