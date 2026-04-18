#include<iostream>
#define Size 100
using namespace std;

class Board {
public:
	static string str[Size]; //최대 사이즈는 100
	static int index;
public:
	static void add(string str);
	static void print();
};

string Board::str[Size]; //이거 동적할당을 하던가 크기 제한을 둬야할 듯.
int Board::index = 0;

void Board::print() {
	cout << "********** 게시판 입니다 **********" << endl;
	for (int i = 0; i < index; i++) {
		cout << i << ": " << str[i] << endl;
	}
}

void Board::add(string s) {
	str[index++] = s;
}

int main() {
	Board::add("중간고사는 감독없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요.");
	Board::print();

	return 0;
}