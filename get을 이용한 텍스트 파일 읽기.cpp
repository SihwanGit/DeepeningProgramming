#include<iostream>
#include<fstream>
using namespace std;

int main() {
	const char* file = "student.txt";
	ifstream fin(file);
	if (!fin) {
		cout << file << " 열기 오류" << endl;
		return 0;
	}

	cout << "문장을 입력하세요(종료는 ^Z) " << endl;
	int count = 0;
	int c;
	while ((c = cin.get()) != EOF) {
		if (c == '\n') break;
		cout << (char)c;
		count++;
	}
	cout << endl;
	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();

	return 0;
}