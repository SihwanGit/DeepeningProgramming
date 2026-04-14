#include<iostream>
using namespace std;

class Container {
private:
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; };
	void consume() { size--; }
	int getSize() { return size; }
};

class CoffeeVendingMachine {
private:
	Container tong[3];	//tong[0]은 커피, tong[1]은 물, tong[2]는 설탕통
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show() {cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕" << tong[2].getSize() << endl; }
public:
	void run();
};

void CoffeeVendingMachine::fill() {
	tong[0].fill(); 
	tong[1].fill(); 
	tong[2].fill();
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕" << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::selectEspresso() {
	if ((tong[0].getSize() == 0)||(tong[1].getSize() == 0)) { //커피 또는 물이 0일 때
		cout << "원료가 부족합니다." << endl;
	}
	else {
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소를 드세요" << endl;
	}
}

void CoffeeVendingMachine::selectAmericano() {
	if ((tong[0].getSize() == 0) || (tong[1].getSize() < 2)) {
		cout << "원료가 부족합니다." << endl;
	}
	else {
		tong[0].consume(); 
		tong[1].consume(); 
		tong[1].consume();
		cout << "아메리카노를 드세요" << endl;
	}
}

void CoffeeVendingMachine::selectSugarCoffee() {
	if ((tong[0].getSize() == 0) || (tong[1].getSize() < 2) || (tong[2].getSize() == 0)) {
		cout << "원료가 부족합니다." << endl;
	}
	else {
		tong[0].consume(); 
		tong[1].consume(); 
		tong[1].consume(); 
		tong[2].consume();
		cout << "설탕커피를 드세요" << endl;
	}
}

void CoffeeVendingMachine::run() {
	int num;
	cin >> num;
	switch (num) {
	case 1:
		selectEspresso();
		break;
	case 2:
		selectAmericano();
		break;
	case 3:
		selectSugarCoffee();
		break;
	case 4:
		show();
		break;
	case 5:
		fill();
		break;
	default:
		break;
	}
}

int main() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	CoffeeVendingMachine cof;
	while (1) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기. 5:채우기)>> ";
		cof.run();
	}
	return 0;
}