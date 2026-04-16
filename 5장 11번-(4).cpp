#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Book {
private:
	string title; //제목 문자열
	int price; //가격
public:
	Book(string title, int price);
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(string title, int price) {
	this->title = title; //C++은 strcpy 안쓰고 연산자로 대입 가능
	this->price = price;
}

void Book::set(string title, int price) {
	this->title = title;
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
/* C-스트링은 char형 변수의 배열로 문자열을 표현한다. 배열의 이름은 포인터와 같다.
* 따라서 C-스트링을 사용한 객체는 복사를 할 때 깊은 복사생성자를 따로 만들어주지 않으면 오류가 발생한다.
* 하지만 string 클래스에서 string은 C-스트링과는 달리 포인터가 아닌 값을 가진 변수이다.
* 얕은 복사의 경우 맴버에 포인터가 없다면 오류가 발생하지 않기 때문에 string 클래스를 사용할 경우 별도의 복사생성자를
* 만들지 않고 디폴트 복사 생성자만 사용해도 정상적으로 복사가 수행된다.
* 
* 덤으로 strcpy()같은 불필요한 함수도 쓸 필요없고, const char*니 char *니 따질 필요없이 string으로 선언하면 되기 때문에
* 사용할 때도 훨씬 편하다.
*/