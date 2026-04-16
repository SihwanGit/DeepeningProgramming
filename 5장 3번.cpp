#include<iostream>
#include<string>
using namespace std;

//두 문자열을 결합하는 함수
void combine(string & text1, string & text2, string & text3) { //string형 참조변수 text1,2,3을 매개변수로 받는다.
	text3 = text1 + ' ' + text2;
} //void 형이므로 반환값은 없다.

int main() {
	string text1, text2;
	cout << "원하시는 문자열을 입력하세요. <문자열 구분은 Enter>" << endl;
	getline(cin, text1);
	getline(cin, text2);
	string text3;
	combine(text1, text2, text3);
	cout << endl << text3 << endl;
	return 0;
}