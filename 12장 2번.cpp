#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ostream& end(ostream& outs) { //심심해서 만들어본 조작자
	outs << endl;
	return outs;
}

int main() {

	ifstream fin("c:\\windows\\system.ini");
	if (!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	//case 1
	int i = 1;
	char buf[100];
	while (fin.getline(buf, 100, '\n')) {
		cout << i << " : " << buf << end;
		i++;
	}
	cout << endl;

	//case 2
	int j = 1;
	string str;
	while (getline(fin, str, '\n')) {
		cout << i << " : " << str << end;
		j++;
	}

	//case1과 2 모두 가능함

	fin.close();
	return 0;
}