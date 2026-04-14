#include<iostream>
using namespace std;
//클래스도 함수 처럼 자기보다 아래쪽에 선언된 얘는 가져다 쓸 수 없다.
//쓰고 싶다면 함수의 원형처럼 미리 있다는 것을 알려야한다.
//전방선언은 포인터를 사용할 때만 쓸 수 있다.
//이 문제는 9번 + 10번이다.

//Circle 클래스
class Circle {
private:
	int radius;
	string name;
public:
	void setCircle(string name, int radius); //이름과 반지름 설정
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

void Circle::setCircle(string name, int radius) { //이름과 반지름 설정
	this->name = name;
	this->radius = radius;
}

class CircleManager {
private:
	Circle* p;
	int size;
public:
	CircleManager(int size);
	~CircleManager() { delete[] p; }
	void setCircle(int index, string name, int radius);
	void searchByName();
	void searchByArea();
};

//CircleManager를 통해 setCircle 실행
void CircleManager::setCircle(int index, string name, int radius) {
	(p + index)->setCircle(name, radius);
}

CircleManager::CircleManager(int size) {
	this->size = size;
	p = new Circle[size]; //Circle의 기본생성자는 컴파일러가 자동 생성
}

void CircleManager::searchByName() {
	cout << endl << "검색하고자 하는 원의 이름 >> ";
	string name;
	int check = 0;
	cin >> name;
	for (int i = 0; i < size; i++) {
		if (name == p[i].getName()) { //검색한 이름을 찾으면
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
			check = 1;
			break;
		}
	}
	if(check == 0)  //검색 목록에 없으면
			cout << name << "은 검색목록에 없습니다." << endl;
}

void CircleManager::searchByArea() {
	cout << endl << "최소 면적을 정수로 입력하세요 >> ";
	int area, check = 0;
	cin >> area;
	for (int i = 0; i < size; i++) {
		if (area <= p[i].getArea()) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ", ";
			check++;
		}
	}
	if (check == 0) {
		cout << area << "보다 큰 원은 없습니다.";
	}
	cout << endl;
}

int main() {
	int n;
	cout << "원의 개수 >> ";
	cin >> n;
	string str;
	int rad;
	CircleManager cir(n);
	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> str >> rad;
		cir.setCircle(i, str, rad);
	}
	cir.searchByName();
	cir.searchByArea();
}