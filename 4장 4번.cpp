#include<iostream>
using namespace std;

class Sample {
private:
	int* p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
		if (!p) cout << "메모리를 할당할 수 없습니다." << endl;
	}
	void read();
	void write();
	int big();
	~Sample() { delete[] p; } //메모리 반환
};

void Sample::read() { //size개 만큼 정수 입력
	for (int i = 0; i < size; i++) cin >> p[i];
}

void Sample::write() { //입력한 수 출력
	for (int i = 0; i < size; i++) cout << *(p + i) << ' ';
	cout << endl;
}

int Sample::big() {
	int max = 0; //최대값의 인덱스
	for (int i = 0; i < size; i++) {
		if (p[max] < p[i]) max = i;
	}
	return *(p + max);
}

int main() {
	int n;
	cout << "정수의 개수를 입력해주세요>> ";
	cin >> n;
	Sample s(n);
	cout << "숫자를 " << n <<"개 입력해주세요" << endl;
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
	return 0;
}