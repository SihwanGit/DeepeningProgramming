#include<iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	int n = 3;
	Circle* pc = new Circle[n];		//크기가 3인 배열의 동적할당
	if (!pc) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}
	cout << "원 " << n << "개의 반지름을 입력하세요" << endl;
	for (int i = 0; i < n; i++) {	//n개의 원에 반지름 입력
		cout << "원 " << i+1 << "의 반지름 >> ";
		int radius;
		cin >> radius;
		pc[i].setRadius(radius);
	}
	int count = 0;	//너비가 100이상인 원의 개수
	for (int i = 0; i < n; i++) {
		if (pc[i].getArea() > 100) count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다." << endl;

	delete[] pc;	//메모리 해제
	return 0;
}