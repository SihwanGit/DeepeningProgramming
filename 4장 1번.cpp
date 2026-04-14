#include<iostream>
using namespace std;

class Color {
private:
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);
	Color* p;
	p = &screenColor;	//(1)
	p->show();			//(2)
	Color color[3];		//(3)
	p = color;			//(4)

	p->setColor(255, 0, 0);			//(5)
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

	p[0].show(); //(6)
	p[1].show();
	p[2].show();

	return 0;
}