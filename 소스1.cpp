#include<iostream>
#include<string>
using namespace std;

int main() {
	int n;
	cout << "입력 받을 이름의 수를 정하세요: ";
	cin >> n;
	string* names = new string[n];

	cout << n << "명의 이름을 입력받겠습니다." << endl;

	for (int i = 0; i < n; i++) {
		cout << "이름[" << i << "]: ";
		getline(cin, names[i], '\n'); 
	}
//이렇게 실행하면 반복문이 이미 1까지 와있는 상태로 실행된다.
//한줄씩 디버그 하다보면 getline()쪽에서 name[0]에는 null이 들어있다.
//cin으로 n을 입력하고 Enter를 누르면 버퍼에 \n이 그대로 남아있다가, getline의 제한자 '\n'을 만나서 한칸을 패스하는 것이다.
//만약 정수로 입력하는 거였다면 이런 문제가 안생겼을 것이다.
//해결하는 법은 검색해보시면 됩니다.

	string latter = names[0];
	for (int i = 0; i < n; i++) {
		if (latter < names[i]) { //문자열끼리도 크기 비교가 가능해졌다.
			latter = names[i];
		}
	}
	cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;

	return 0;
}