#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cout << "문자열 입력>> ";
	getline(cin, str);
	
	int count = 0; //a의 개수
	for (int i = 0; i < str.length(); i++) { //0부터 str의 길이까지
		if (str[i] == 'a') count++; //만약 str[i]가 a면 count++
	}
	cout << "문자 a는 " << count << "개 있습니다." << endl;

	return 0;
}
