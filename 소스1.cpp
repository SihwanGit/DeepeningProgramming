#include<iostream>
using namespace std;

float square(float a) { return a * a; }
double square(double a) { return a * a; }

int main() {
	square(3); //함수 중복으로 인한 컴파일 오류가 일어난다.
	return 0;
}