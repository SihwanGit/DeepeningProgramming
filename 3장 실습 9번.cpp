#include<iostream>
using namespace std;

class Oval {
	int width, height; //너비와 높이
public:
	Oval() { width = 1, height = 1; } //너비, 높이 1로 초기화
	Oval(int w, int h) { width = w, height = h; } //너비와 높이 값을 매개변수로 받는 생성자
	~Oval() { cout << "Oval 소멸 : width = " << width << ", height = " << height << endl; } //너비,높이를 출력하는 소멸자
	int getWidth() { return width; } //너비 리턴
	int getHeight() { return height; } //높이 리턴
	void set(int w, int h) { width = w, height = h; } //타원의 너비와 높이 변경
	void show() {cout << "width = " << width << ", height = " << height << endl; } //너비와 높이 출력
};

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << "," << b.getHeight() << endl;

	return 0;
}