#pragma once
class Rect;
class RectManager;
//이거 구현 순서에 무슨 조건이 있는듯

class Rect {
	int width, height;
public:
	Rect(int width, int height) { this->height = height; this->width = width; }
	friend bool equals(Rect r, Rect s);
	//friend bool RectManager::equals(Rect r, Rect s);
	friend RectManager;
};

bool equals(Rect r, Rect s) { //case 1
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
} //friend를 선언하지 않으면 private 맴버에 접근하므로 컴파일 에러 발생

class RectManager {
public:
	bool equals(Rect r, Rect s);
};

bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}