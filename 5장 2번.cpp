#include<iostream>
using namespace std;

//n을 반으로 나누는 함수
void half(double & n) { //double형 참조변수 n을 매개변수로 받는다.
	n = n / 2;
} //void 형이므로 반환값은 없다

int main() {
	double n;
	cout << "원하는 값을 입력하세요 >> ";
	cin >> n;
	cout << n << "을 반으로 나눈 값 = ";
	half(n);
	cout << n << endl;
	return 0;
}