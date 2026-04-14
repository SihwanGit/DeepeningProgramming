#include<iostream>
using namespace std;

class CoffeeMachine {
private:
	int coffee, water, sugar; //커피, 물, 설탕
public:
	CoffeeMachine(int c, int w, int s) { coffee = c, water = w, sugar = s; }
	void drinkAmericano() { coffee -= 1, water -= 2; } //커피1, 물2 소모
	void drinkEspresso() { coffee -= 1, water -= 1; } //커피1, 물1 소모
	void dringSugarCoffee() { coffee -= 1, water -= 2, sugar -= 1; } //커피1, 물2, 설탕1 소모
	void show() { cout << "커피 머신 상태, 커피:" << coffee << " 물: " << water << " 설탕: " << sugar << endl; }
	void fill() { coffee = 10, water = 10, sugar = 10; } //각각 10으로 초기화
};

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.dringSugarCoffee();
	java.show();
	java.fill();
	java.show();
	return 0;
}