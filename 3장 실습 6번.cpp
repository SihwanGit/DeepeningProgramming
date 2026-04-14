#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class EvenRandom {
public:
	int next() { return 2*(rand() % (RAND_MAX/2)); } //0부터 RNAD_MAX까지의 짝수 리턴
	int nextInRange(int a, int b); //a부터 b까지의 짝수 리턴
};

int EvenRandom::nextInRange(int a, int b) {
	int x;
	x = a + rand() % (b - a + 1);
	if (x%2 == 0) { //만약 랜덤 값이 짝수면
		return x;
	}
	else { //만약 랜덤 값이 홀수면
		if (x+1 > b) { //랜덤값+1이 주어진 범위를 넘으면 
			return x - 1; //랜덤값-1
		}
		else {
			return x + 1; //랜덤 값 + 1
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	EvenRandom r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); //0부터 RNAD_MAX까지의 짝수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 10까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10); //2부터 10사이의 난수
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}