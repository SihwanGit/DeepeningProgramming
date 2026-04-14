#include<iostream>
#include<string>
using namespace std;

class Account {
	string name; //ÀÌ¸§
	int id; //°èÁÂ¹øÈ£
	int balance = 0; //ÀÜ¾×
public:
	Account(string n, int i, int b);
	void deposit(int a) { balance += a; } //ÀÜ¾× Àú±İ
	int withdraw(int a) { balance -= a; return balance; } //ÀÜ¾× Ãâ±İ
 	string getOwner() { return name; }
	int inquiry() { return balance; }
};

Account::Account(string n, int i, int b) {
	name = n;
	id = i;
	balance = b;
}

int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº " << a.inquiry() << endl;

	return 0;
}