#include<iostream>
#include<string>
using namespace std;

//문자열 a에서 c를 찾는 함수
char& find(char a[], char c, bool& success) {//문자열 a, 문자 c, bool형 참조변수 success를 매개변수로 받는다.
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	}
	return a[0]; //만약 c가 없으면 a[0]리턴
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl; 
	find(s, 'M', b) = 'L'; //s[0] = 'L'
	cout << s << endl;
	//만약 s와 find함수의 매개변수 a를 string으로 설정하면 mike로 변경안됨.
	//string과 char[]은 별개 취급인듯.
	//테스트해보니까 string하고 char[]이 대입은 되는데, 참조변수를 사용하면 오류가 남.
	return 0;
}