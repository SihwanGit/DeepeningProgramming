#include<iostream>
#include<string>
using namespace std;

class Phone {
	string name;
	string telnum;
	string address;
public:
	Phone(string n = "", string t = "", string a = "") {
		name = n;
		telnum = t;
		address = a;
	}
	friend istream& operator >> (istream& ins, Phone& p);
	friend ostream& operator << (ostream& outs, Phone p);
};

istream& operator >> (istream& ins, Phone& p) {
	cout << "이름 >> ";
	getline(cin, p.name);
	cout << "전화번호 >> ";
	ins >> p.telnum;
	cout << "주소 >> ";
	ins.ignore(1);
	getline(cin, p.address);
	return ins;
}

ostream& operator << (ostream& outs, Phone p) {
	cout << '(' << p.name << ',' << p.telnum << ',' << p.address << ')';
	return outs;
}

int main() {
	Phone girl, boy;
	cin >> girl >> boy;
	cout << girl << endl << boy << endl;

	return 0;
}