#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char name[20], adress[50], age[5];
	cout << "이름은?";
	cin.getline(name, 20); //이름 입력
	cout << "주소는?";
	cin.getline(adress, 50); //주소 입력
	cout << "나이는?";
	cin.getline(age, 5); // 나이 입력
	cout << name << ", " << adress << ", " << age << "세\n"; //순서대로 출력
	return 0;
}