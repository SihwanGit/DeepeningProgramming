#include<iostream>
#include<fstream>
using namespace std;

int main() {

	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}
	fin.seekg(0, ios::end);
	long len = fin.tellg(); //fin의 바이트 수
	fin.seekg(0, ios::beg); //다시 getpointer을 처음 위치로

	ofstream fout("c:\\temp\\system.txt");
	if (!fout) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	//fin의 바이트 수를 세고, count == i*(바이트/10), i++을 만족할 때마다 퍼센트를 출력한다.

	int ch, count = 0, i = 1;
	cout << "복사 시작..." << endl;
	while ((ch = fin.get()) != EOF) {
		if (count == i * ((int)len / 10)) { //처음엔 21B랑 같으면 10%, i++하고 42B랑 같으면 20%출력 ....
			cout << "." << len/10 << "B " << i * 10 << "%" << endl;
			i++;
		}
		fout << (char)ch;
		count++;
	}
	cout << "." << len / 10 << "B " << i * 10 << "%" << endl; //100%는 따로 출력
	cout << len << "B 복사 완료" << endl;

	fin.close();
	fout.close();
	return 0;
}