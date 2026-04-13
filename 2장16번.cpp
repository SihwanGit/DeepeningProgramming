#include<iostream>
#include<cstring>
using namespace std;
void count_alpha(char* buf, int* alpha);

int main() {
	char buf[10000];
	int alpha[26] = {0};
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다.\n";
	cout << "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다.\n";
	cin.getline(buf, 10000, ';');
	count_alpha(buf, alpha);
	return 0;
}

//입력된 문장에서 알파벳들의 개수를 새는 함수
void count_alpha(char* buf, int* alpha) { //문자열 배열 buf와 알파벳 개수 alpha를 매개변수로 가진다.
	for (int i = 0; i < strlen(buf); i++) {
		if ((buf[i] >= 'A') && (buf[i] <= 'Z')) { //입력한 문장이 알파벳 대문자면...
			alpha[buf[i]-65] += 1; //알파벳 개수 +1
		}
		else if ((buf[i] >= 'a') && (buf[i] <= 'z')) { //입력한 문장이 알파벳 소문자면
			alpha[buf[i]-97] += 1; //알파벳 개수 +1
		}
	}
	
	int count = 0;
	for (int i = 0; i < 26; i++) {
		count += alpha[i];
	}
	cout << "총 알파벳 수 "<< count << endl;
	cout << endl;
	for (int i = 0; i < 26; i++) {
		cout << char(i+97) << " (" << alpha[i] << ")	:	";
		for (int j = 0; j < alpha[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
} //void 형이므로 반환값은 없다.