#include<iostream>
using namespace std;


//범위 내의 두 정수의 최대값을 구하는 함수
int big(int a, int b, int range = 100) { //두 정수 a,b와 범위 range를 매개변수로 받음, 범위의 기본값은 100
	if (a > b) {
		if (a > range)
			return range; //최대값이 범위를 넘어서면 range리턴
		else
			return  a;
	}
	else {
		if (b > range)
			return range;
		else
			return b;
	}
}

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << ' ' << endl;
	return 0;
}