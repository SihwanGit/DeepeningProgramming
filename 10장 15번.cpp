#include<iostream>
#include<vector>
using namespace std;

class Circle {
private:
	string name;
	int radius;
public:
	Circle(int r, string n) {
		radius = r; name = n;
	}
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

int main() {
	vector<Circle> v;
	vector<Circle>::iterator it; //it선언

	cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl << endl;
	int check = 0;
	int c, r;
	string name;
	while(check != 1) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4  >> ";
		cin >> c;
		if (c == 1) {
			cout << "생성하고자 하는 원의 반지름과 이름은 >> ";
			cin >> r >> name;
			Circle cir(r, name);
			v.push_back(cir); //벡터 삽입
			cout << endl;
		}
		else if (c == 2) {
			cout << "삭제하고자 하는 원의 이름은 >> ";
			cin >> name;
			for (it = v.begin(); it != v.end();) { //it++ 쓰면 오류 발생한다.(erase때문에 it값에 오류 생김)
				if (name == it->getName()) it = v.erase(it); //얘가 삭제한 곳의 다음 인덱스를 반환
				else it++; //얘 안쓰면 무한루프에 빠져버림
			}
			cout << endl;
		}
		else if (c == 3) { //모두 보기
			for (it = v.begin(); it != v.end(); it++) { 
				cout << it->getName() << endl;
			}
			cout << endl;
		}
		else if (c == 4) {
			check = 1; //반복 종료
		}
		else { //에러 처리
			cout << "다시 입력해주세요" << endl << endl;
		}
	}
	cout << "프로그램을 종료합니다..." << endl;
	return 0;
}