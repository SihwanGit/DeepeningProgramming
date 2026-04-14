#include<iostream>
#include<string>
using namespace std;

class Date {
public:
	int year, month, day;
	Date(int y, int m, int d) { year = y, month = m, day = d; }
	Date(string date);
	int getYear() { return year; } //년 출력
	int getMonth() { return month; } //월 출력
	int getDay() { return day; } //일 출력
	void show() { cout << year << "년" << month << "월" << day << "일" << endl;} //전체 출력
};

Date::Date(string date) { //문자열 date를 substr을 사용해 '/'를 기준으로 3개의 문자열로 나눠서 각각 stoi()
	string s[3];
	int a[2], j = 0;
	for (int i = 0; i < date.length(); i++) { // '/'가 나오는 인덱스 찾기
		if (date[i] == '/') {
			a[j++] = i;
		}
	}
	//substr(시작 인덱스, 길이)
	s[0] = date.substr(0, a[0]); //index 0부터 a[4]개
	s[1] = date.substr(a[0]+1, (a[1]-a[0]-1)); //index a[0]+1부터 (a[1]-a[0]-1)개
	s[2] = date.substr(a[1]+1); //index a[1]+1부터 끝까지
	year = stoi(s[0]);
	month = stoi(s[1]);
	day = stoi(s[2]);
}

int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.year << ',' << birth.month << ',' << birth.day << endl;
	return 0;
}