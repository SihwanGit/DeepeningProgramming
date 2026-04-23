#include<iostream>
using namespace std;

class GraphicEditor {
protected:
	int index; //도형들의 index
	GraphicEditor* next; //다음 노드의 포인터 저장, 연결리스트
public:
	void call();
};

class Shape {
protected:
	int index;
	Shape* next;
	virtual void draw()=0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void print();
	Shape* add(Shape* p);
	Shape* getNext() { return next; }
};

class Line : public Shape {
private:
	void draw() { cout << "Line" << endl; }
};

class Circle : public Shape {
	void draw() { cout << "Circle" << endl; }
};

class Rect : public Shape {
	void draw() { cout << "Rect" << endl; }
};

int main() {
	cout << "그래픽 에디터입니다." << endl;
	int s = 0, i = 0; //s는 반복문 선택, i는 인덱스나 도형 선택
	while (s != 4) {
		cout << "삽입:1, 삭제:2, 모두 보기:3, 종료:4 >> ";
		cin >> s;
		switch (s) {
		case 1:
			cout << "선:1, 원:2, 사각형:3 >> ";
			cin >> i;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			while (!(s >= 1 && s <= 4)) {
				cout << "다시 입력해 주세요 >> ";
				cin >> s;
			}
		}
	}

	return 0;
}