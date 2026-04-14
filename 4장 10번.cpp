#include<iostream>
#include<string>
using namespace std;

class Person {
private:
	string name;
public:
	Person(); //기번생성자 선언
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

Person::Person() { //선언과 정의를 전부 해야된다.
	//기본 생성자를 정의하지 않고 해결하고 싶다면 Person(string name) 생성자를 없애버려서
	//자동으로 기본생성자가 정의되게끔 해도 된다.
}

class Family {
private:
	Person* p; //Person 배열의 포인터
	//포인터는 private로 보호받는 중. 따라서 p의 값을 바꾸기 위해선 Family의 맴버 함수 내에서 바꿔야함.
	//포인터 자체는 값이 없음. 그러므로 맴버함수에서 Person형 변수를 만들고, p로 그 변수의 주소를 가질 것.
	//동적할당을 포함해서.
	int size;
	string name;
public:
	Family(string name, int size);
	void show();
	void setName(int num, string name);
	~Family() { delete[] p; }
};

Family::Family(string name, int size) {
	this->name = name; //가족이름
	this->size = size;
	p = new Person[3];
	//입력한 크기로 동적할당을 받는다.
	//받은 동적할당은 클래스가 끝날때 해제해줘야하므로 소멸자에서 해제한다.
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
	}
}

void Family::setName(int index, string name) {
	(p + index)->setName(name); //생성자에서 Person배열의 동적할당을 만들었고, 인덱스와 문자열을 받아 Person배열에 접근한다.
}

void Family::show() {
	cout << name <<" 가족은 다음과 같이 " << size << "명입니다." << endl;
	for (int i = 0; i < size; i++) {
		cout << (p + i)->getName() << " ";
	}
	cout << endl;
}

int main() {
	Family* simpson = new Family("Simpson", 3); //3명으로 구성된 심슨 가족. 얘는 배열이 아님. size를 받아 그 배열을 만들어야겠네.
	//심슨은 가족 이름. 가족이름을 다루는 변수를 하나 더 만들어야함.
	simpson->setName(0, "Mr.Simpson"); //심슨은 인덱스 0을 가지고있다.
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");
	simpson->show();

	delete simpson;
	return 0;
}