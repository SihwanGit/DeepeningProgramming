#pragma once //한 번만 선언한다는 뜻

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};

//클래스 선언부, 전역변수, 구조체, 상수, 헤더파일 등이 들어갈 수 있다.
