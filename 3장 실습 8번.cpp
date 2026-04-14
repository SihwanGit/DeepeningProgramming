#include<iostream>
#include<string>
using namespace std;

class Integer {
	int n;
public:
	Integer(int r);
	Integer(string s);
	int get();
	void set(int r);
	bool isEven();
};

inline Integer::Integer(int r) { n= r; } //정수 할당 생성자
inline Integer::Integer(string s) { n = stoi(s); }//문자열 정수 변환 생성자
inline int Integer::get() { return n; } //정수 반환
inline void Integer::set(int r) { n = r; }//정수 설정
inline bool Integer::isEven() { if (n % 2 == 0) return true;  else return false; }//홀짝 판단

int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven();

	return 0;
}