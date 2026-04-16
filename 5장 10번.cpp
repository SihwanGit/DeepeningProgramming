#include<iostream>
#include<string>
using namespace std;

class Buffer {
private: 
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { text += next; }
	void print() { cout << text << endl; }
};

//Buffer에 text를 더하는 함수.
Buffer& append(Buffer& buf, string text) {
//바뀐 값이 buf에도 영향을 줘야한다. Buffer의 참조형과 string text를 매개변수로 받는다.
	buf.add(text);
	return buf;
} //Buffer형 참조변수 buf를 반환한다.

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");
	temp.print();
	buf.print();
	return 0;
}
