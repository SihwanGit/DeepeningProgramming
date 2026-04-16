#include<iostream>
using namespace std;

//두 정수를 비교해 더 큰 값을 구하는 함수
bool bigger(int a, int b, int& big) { //두 정수 a,b와 참조변수 big을 가진다.
	if (a == b) {
		big = a;
		cout << a << " 와/과 " << b << "는 같다." << endl;
		return true;
	}
	else {
		if (a > b) big = a;
		else big = b;
		cout << a << " 와/과 " << b << " 중 더 큰 수는 " << big << "이다." << endl;
		return false;
	}
} //bool형이므로 true와 false를 반환한다.

int main() {
	int a, b, big;
	cout << "두 수를 입력하세요" << endl;
	cout << "a >> ";
	cin >> a;
	cout << "b >> ";
	cin >> b;
	bigger(a, b, big);
	return 0;
}