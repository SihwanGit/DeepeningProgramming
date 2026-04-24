#include<iostream>
#include<vector>
using namespace std;

class Shape {
protected:
	virtual void draw() = 0;
public:
	void paint() { draw(); }
};

class Circle : public Shape {
protected:
	virtual void draw() {
		cout << "Circle" << endl;
	}
};

class Rect : public Shape {
protected:
	virtual void draw() {
		cout << "Rectangle" << endl;
	}
};

class Line : public Shape {
protected:
	virtual void draw() {
		cout << "Line" << endl;
	}
};

int main() {
	vector<Shape *> v;
	vector<Shape*>::iterator it;
	int check = 0;

	while (check != 1) {
		int c;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> c;
		if (c == 1) {
			int sh;
			while (1) {
				cout << "선:1, 원:2, 사각형:3 >> ";
				cin >> sh;
				if (sh == 1) {
					Shape* s = new Line;
					v.push_back(s);
					cout << endl;
					break;
				}
				else if (sh == 2) {
					Shape* s = new Circle;
					v.push_back(s);
					cout << endl;
					break;
				}
				else if (sh == 3) {
					Shape* s = new Rect;
					v.push_back(s);
					cout << endl;
					break;
				}
				else {
					cout << "다시 입력해주세요" << endl;
				}
			}
		}
		else if (c == 2) { //삭제
			it = v.begin();
			int i;
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			cin >> i;
			for (int j = 0; j < i; j++) { //it가 삭제하고자하는 인덱스까지 이동.
				it++;
			}
			it = v.erase(it);
			cout << endl;
		}
		else if (c == 3) { //모두보기
			for (int i = 0; i < v.size(); i++) {
				cout << i << ": ";
				v[i]->paint();
			}
			cout << endl;
		}
		else if (c == 4) { //종료
			check = 1;
			cout << endl;
		}
		else {
			cout << "다시 입력해주세요." << endl;
		}
	}
	cout << "프로그램을 종료합니다..." << endl;
	return 0;
}