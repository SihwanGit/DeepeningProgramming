#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class Book {
private:
	char* title; //제목 문자열
	int price; //가격
public:
	Book(const char* title, int price);
	~Book();
	Book(const Book& book);
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price) {
	//title은 const char* "명품 C++"의 주소를 갖는다.
	int len = strlen(title);
	this->title = new char[len+1];
	strcpy(this->title, title);
	this->price = price;
}

Book::~Book() {
	delete[] title;
}

Book::Book(const Book& book) { //깊은 복사 생성자
	this->price = book.price;
	int len = strlen(book.title);
	this->title = new char[len + 1];
	strcpy(this->title, book.title);
}

void Book::set(const char* title, int price) {
	delete[] this->title;
	int len = strlen(title);
	this->title = new char[len+1];
	strcpy(this->title, title);
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; //묵시적 복사 생성자 호출
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}