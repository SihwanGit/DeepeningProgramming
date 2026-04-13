#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "끝 수를 입력하세요>>"; //printf를 cout으로 대체
	cin >> n; //scanf를 cin으로 대체
	int sum = 0; //변수를 실행문 중간에 생성
	for (int k = 1; k <= n; k++) { //for문의 ()안에 변수 k 선언
		sum += k;
	}
	cout << "1부터 " << n << "까지의 합은 " << sum << "입니다.\n"; //printf를 cout으로 대체

	return 0;
}