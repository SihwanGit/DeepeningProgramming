#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char n[100];
	while (1) {
		cout << "종료하고싶으면 yes를 입력하세요>> ";
		cin.getline(n, 100);
		if (strcmp(n, "yes") == 0) { //n이 yes면 반복 종료
			//n == "yes"처럼 == 연산자를 사용하면 안된다.
			cout << "종료합니다...\n";
			break;
		}
	}
	
	return 0;
}