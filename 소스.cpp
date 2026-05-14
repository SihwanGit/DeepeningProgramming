#include"Çì´õ.h"

int main() {
	Point p;
	p.set(2, 3);
	//p.x = 5; //protected
	//p.y = 5; //protected
	p.show();

	ColorPoint cp;
	//cp.x = 5; //protected
	//cp.y = 5; //protected
	cp.set(3, 4);
	cp.setColor("Red");
	cp.showColorPoint();

	ColorPoint cp2;
	cp2.set(3, 4);
	cp2.setColor("Red");
	cout << ((cp.equal(cp2)) ? "true" : "false");

	return 0;
}
