#include<iostream>
#define Size 100
using namespace std;

class Trace {
	static string stag[Size];
	static string sstr[Size];
	static int index;
public:
	static void print(string tag);
	static void print();
	static void put(string tag, string str);
};

string Trace::stag[Size];
string Trace::sstr[Size];
int Trace::index = 0;

void Trace::put(string tag, string str) {
	stag[index] = tag;
	sstr[index] = str;
	index++;
}

void Trace::print() { //전체 출력
	cout << endl << "---- 모든 Trace 정보를 출력합니다. ----" << endl;
	for (int i = 0; i < index; i++) {
		cout << stag[i] << ": " << sstr[i] << endl;
	}
}

void Trace::print(string tag) {
	cout << endl << "---- " << tag << "태그의 Trace 정보를 출력합니다. ----" << endl;
	for (int i = 0; i < index; i++) {
		if (stag[i] == tag) {
			cout << stag[i] << ": " << sstr[i] << endl;
		}
	}
}

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요 >> ";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력받았음"); //디버깅 정보 저장
	c = a + b;
	Trace::put("f()", "합 계산"); //디버깅 정보 저장
	cout << "합은 " << c << endl;
}

int main() {
	Trace::put("main()", "프로그램을 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
	
	return 0;
}