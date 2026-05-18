#include<iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};

class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; } //여기엔 virtual을 안붙여도 가능
};

int main() {
	Derived d, * pDer;
	pDer = &d;
	pDer->f(); //Derived의 f()가 호출

	Base* pBase;
	pBase = pDer;
	pBase->f(); //Base의 f()가 호출, virtual 키워드를 붙인다면 Derive::f()가 호출

	return 0;
}