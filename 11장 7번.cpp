#include<iostream>
#include<cctype>
using namespace std;

int main() {

	cout.setf(ios::left);
	for (int i = 0; i < 4; i++) {
		cout.width(6);
		cout << "dec";
		cout.width(6);
		cout << "hexa";
		cout.width(6);
		cout << "char";
	}
	cout << endl;
	
	for (int i = 0; i < 4; i++) {
		cout.width(6);
		cout << "___";
		cout.width(6);
		cout << "____";
		cout.width(6);
		cout << "____";
	}
	cout << endl;

	for (int i = 0; i < 32; i++) {
		cout.width(6);
		cout << dec << i*4;
		cout.width(6);
		cout << hex << i*4;
		if (isprint(i * 4) == false) { //만약 출력 못하면
			cout.width(6);
			cout << "."; //그냥 . 출력
		}
		else {
			cout.width(6);
			cout << (char)(i*4);
		}

		cout.width(6);
		cout << dec << i * 4 + 1;
		cout.width(6);
		cout << hex << i * 4 + 1;
		if (isprint(i * 4 + 1) == false) {
			cout.width(6);
			cout << ".";
		}
		else {
			cout.width(6);
			cout << (char)(i * 4 + 1);
		}

		cout.width(6);
		cout << dec << i * 4+2;
		cout.width(6);
		cout << hex << i * 4+2;
		if (isprint(i * 4+2) == false) {
			cout.width(6);
			cout << ".";
		}
		else {
			cout.width(6);
			cout << (char)(i * 4 + 2);
		}

		cout.width(6);
		cout << dec << i * 4 + 3;
		cout.width(6);
		cout << hex << i * 4 + 3;
		if (isprint(i * 4 + 3) == false) {
			cout.width(6);
			cout << ".";
		}
		else {
			cout.width(6);
			cout << (char)(i * 4 + 3);
		}
		cout << endl;
	}
	return 0;
}