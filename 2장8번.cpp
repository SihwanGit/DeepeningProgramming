#include<iostream>
#include<cstring>
#define len 5 //반복 회수
using namespace std;

int main() {
	cout << "5명의 이름을 ';'으로 구분하여 입력하세요.\n>>";
	char name[len][100];
	int le[len];
	
	for (int i = 0; i < len; i++) {
		cin.getline(name[i], 100, ';'); //배열들에 이름 저장
		cout << i+1 << ": " << name[i] << '\n'; 
	}

	int max = 0;
	for (int i = 0; i < len; i++) {
		if (strlen(name[max]) < strlen(name[i])) { //가장 큰 길이의 문자열 구하기
			max = i;
		}
	}
	cout << "가장 긴 이름은 " << name[max]; //가장 긴 이름 출력

	return 0;
}