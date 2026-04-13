#include<iostream>

int main() {
	using std::cout;
	double num[5];
	int max = 0;
	cout << "5개의 실수를 입력하라 >> ";
	for (int i = 0; i < 5; i++) std::cin >> num[i]; //실수 입력
	for (int i = 0; i < 5; i++) { 
		if (num[max] <= num[i]) max = i; //최대값
	}
	cout << "제일 큰 수 = " << num[max]; //최대값 출력
	return 0;
}