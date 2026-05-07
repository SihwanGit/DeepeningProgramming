#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	string address("서울시 성북구 삼선동 389");
	string copyAddress(address);

	char text[] = { 'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'};
	string title(text);

	cout << str << endl;
	cout << address << endl;
	cout << copyAddress << endl;
	cout << title << endl;
	cout << title[2] << endl; //이렇게 배열처럼 접근도 가능

	return 0;
}