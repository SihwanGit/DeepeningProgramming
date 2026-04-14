#include"Box.h"

Box::Box(int w, int h) { setSize(w, h); fill = '*'; } //Box(int w, int h) 备泅何

void Box::setFill(char f) { fill = f; } //setFill 备泅何

void Box::setSize(int w, int h) { width = w; height = h; } //setSize 备泅何

void Box::draw() { //draw 备泅何
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) cout << fill;
		cout << endl;
	}
}