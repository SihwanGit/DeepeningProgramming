#include<iostream>
using namespace std;

int sum(int a, int b); //함수 원형

int main() {
	int n;
	cout << "끝 수를 입력하세요>>";
	cin >> n;
	cout << "1부터 " << n << "까지의 합은 " << sum(1, n) << "입니다.\n";

	return 0;
}

//a부터 b까지의 합을 구하는 함수
int sum(int a, int b) { //시작부분인 a와 끝나는 부분인 b를 매개변수로 가진다.
	int res = 0;
	for (int k = a; k <= b; k++) { //a부터 b까지의 합
		res += k;
	}
	return res; //a부터 b까지의 합을 리턴한다.
}