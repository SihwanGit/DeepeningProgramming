#include<iostream>

int main() {
	int num[2];
	using std::cout;
	cout << "두 수를 입력하라>> ";
	std::cin >> num[0] >> num[1]; //두 수 입력
	if (num[0] >= num[1]) cout << "큰 수= " << num[0] << "\n"; //더 큰 수 출력
	else cout << "큰 수= " << num[1] << "\n"; //더 큰 수 출력
	return 0;
}