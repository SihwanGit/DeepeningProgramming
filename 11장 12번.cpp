#include<iostream>
using namespace std;

class CoffeeSimul {
private:
	int Coffee;
	int Sugar;
	int Cream;
	int Water;
	int Cup;
public:
	void set(int c) { //초기값 설정
		Coffee = c; Sugar = c; Cream = c; Water = c; Cup = c;
	}
	int getCoffee() { return Coffee; }
	int getSugar() { return Sugar; }
	int getCream() { return Cream; }
	int getWater() { return Water; }
	int getCup() { return Cup; }

	void spendCoffee() { Coffee -= 1; }
	void spendSugar() { Sugar -= 1; }
	void spendCream() { Cream -= 1; }
	void spendWater() { Water -= 1; }
	void spendCup() { Cup -= 1; }
};

ostream& operator << (ostream& out, CoffeeSimul c) {
	out << "Coffee" << '\t';
	for (int i = 0; i < c.getCoffee(); i++) out << "*";
	out << endl;
	out << "Sugar" << '\t';
	for (int i = 0; i < c.getSugar(); i++) out << "*";
	out << endl;
	out << "Cream" << '\t';
	for (int i = 0; i < c.getCream(); i++) out << "*";
	out << endl;
	out << "Water" << '\t';
	for (int i = 0; i < c.getWater(); i++) out << "*";
	out << endl;
	out << "Cup" << '\t';
	for (int i = 0; i < c.getCup(); i++) out << "*";
	out << endl;

	return out;
}

int main() {
	CoffeeSimul c;
	c.set(3);
	cout << "-----명품 커피 자판기 켭니다.-----" << endl;
	cout << c << endl;
	int check = 0;

	while (check != 1) {
		int ch;
		cout << "보통 커피: 0, 설탕 커피: 1, 블랙 커피: 2, 채우기:3, 종료:4 >> ";
		cin >> ch;
		switch (ch) {
		case 0:
			c.spendCoffee();
			c.spendCup();
			c.spendWater();
			cout << "맛있는 보통 커피 나왔습니다~~~" << endl << c << endl;
			break;
		case 1:
			c.spendCoffee();
			c.spendSugar();
			c.spendCup();
			c.spendWater();
			cout << "맛있는 설탕 커피 나왔습니다~~~" << endl << c << endl;
			break;
		case 2:
			c.spendCoffee();
			c.spendCream();
			c.spendCup();
			c.spendWater();
			cout << "맛있는 블랙 커피 나왔습니다~~~" << endl << c << endl;
			break;
		case 3:
			c.set(3);
			cout << "모든 통을 채웁니다." << endl << c << endl;
			break;
		case 4:
			check = 1;
			cout << "프로그램을 종료합니다" << endl;
		default:
			cout << "다시 입력해주세요." << endl << endl;
			break;
		}
	}
 
	return 0;
}