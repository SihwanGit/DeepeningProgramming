#include<iostream>
using namespace std;
#define size 3

class Person {
private:
	string name;
	string tel;
public:
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel) { this->name = name; this->tel = tel; }
};
void input_Per(Person* per); //사람 입력
void output_Per(Person* per); //사람 출력
void search_Per(Person* per); //사람 검색

int main() {
	Person per[size]; //크기가 3
	cout << "이름과 전화번호를 입력해주세요\n";
	input_Per(per);
	output_Per(per);
	search_Per(per);
	return 0;
}

//Person 클래스의 *per 객체를 매개변수로 받는다.
void input_Per(Person* per) { //개인정보를 입력하는 함수
	string name, tel;
	for (int i = 0; i < size; i++) { //이름과 전화번호 입력
		cout << "사람 " << i + 1 << ">> ";
		cin >> name >> tel;
		per[i].set(name, tel);
	}
} //void형이므로 return 값은 없다.

//Person 클래스의 *per 객체를 매개변수로 받는다.
void output_Per(Person* per) { //개인정보를 출력하는 함수
	cout << endl;
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < size; i++) //이름출력
		cout << per[i].getName() << " ";
	cout << endl;
}//void형이므로 return 값은 없다.

//Person 클래스의 *per 객체를 매개변수로 받는다.
void search_Per(Person* per) { //이름을 입력해 전화번호를 알려주는 함수
	string name;
	int check = 0;
	cout << endl << "전화번호를 검색합니다. 이름을 입력하세요>> ";
	while (1) {
		cin >> name;
		for (int i = 0; i < 3; i++) {
			if (name == per[i].getName()) { //검색한 이름을 찾으면
				cout << per[i].getName() << "님의 전화번호는 " << per[i].getTel() << endl;
				check = 1;
				break;
			}
		}
		if (check == 1) break;
		else  //검색 목록에 없으면
			cout << name << "님은 검색목록에 없습니다. 다시 입력하세요 >> ";
	}
} //void형이므로 반환값은 없다.

