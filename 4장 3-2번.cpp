#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cout << "문자열 입력>> ";
	getline(cin, str);

	int count = 0; //a의 개수
	int index = str.find('a', 0); //str에서 a가 있는 인덱스 
	while (index != -1) { //끝까지 탐색했을 때
		count++;
		index = str.find('a', index+1);
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;

	return 0;
}
