#include<iostream>
using namespace std;

class Tower { //class 선언부
	int height;
public:
	Tower();
	Tower(int h) { height = h; }
	int getHeight() { return height; } //높이 반환
};
Tower::Tower() : Tower(1) {}; //위임 생성자 사용

int main() {
	Tower myTower; //매개 변수가 없는 Tower 생성자 호출
	Tower seoulTower(100);
	cout << "높이는" << myTower.getHeight() << "미터" << endl;
	cout << "높이는" << seoulTower.getHeight() << "미터" << endl;
	return 0;
}