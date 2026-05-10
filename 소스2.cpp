#include<iostream>
using namespace std;

class Person {
public:
	int money; //non-static
	void addMoney(int money) { this->money = money; } //non-static

	static int sharedMoney; //static
	static void addShared(int n) { sharedMoney += n; } //static
};

int Person::sharedMoney = 10; //전역변수 공간에 생성.

int main() {
	Person::addShared(50);
	cout << Person::sharedMoney << endl; //이름 공간으로 접근 가능
	//객체를 생성하지 않은 상태에서도 가능한 것을 볼 수 있다.

	Person han;
	han.money = 100;
	han.sharedMoney = 200;
	Person::sharedMoney = 300;
	Person::addShared(100);

	cout << han.money << ' ' << Person::sharedMoney << endl;

	return 0;
}