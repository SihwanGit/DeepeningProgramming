#include<iostream>
using namespace std;

int main() {
	int ch;

	cout << "영어문장;한글문장 형식으로 입력해주세요 >> ";
	while ((ch = cin.get()) != EOF) {
		char p = (char)ch;
		if (p == ';') {
			p = '\n'; //p == ';'이면 p를 강제개행으로 바꿔버림.
			cin.ignore(100, '\n'); //;를 만나면 \n까지 ignore
			cout << endl; //한칸 강제 개행
			cout << "영어문장;한글문장 형식으로 입력해주세요 >> ";
			//??? ignore 다음에 cout이 안되는게 아니라 buf를 함부로 건드리면 안되는 거인듯.
		}
		else {
			cout << p; //ch를 출력하게 만들면 ;도 출력되기 떄문에 p를 한번 거쳐서 ;가 나오면 p가 ;를 출력하지 않게끔 변경.
		}
		//p가 ;가 아니면 그냥 출력하고 ;면 ignore한 다음 다음 문장 입력
	}
	return 0;
}