#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class SelectableRandom {
public:
	int next(char c); //0부터 RNAD_MAX사이의 홀수 리턴
	int nextInRange(int a, int b, char c); //a부터 b까지의 홀수 리턴
};

int SelectableRandom::next(char c) {
	if (c == 'E') {
		return 2 * (rand() % (RAND_MAX / 2)); //0부터 RAND_MAX 사이의 짝수 리턴
	}
	else if (c == 'O') {
		return (2 * (rand() % (RAND_MAX / 2)) + 1); //0부터 RNAD_MAX사이의 홀수 리턴
	}
}

int SelectableRandom::nextInRange(int a, int b, char c) {
	int x;
	if (c == 'E') { //짝수를 출력해야한다면
		x = a + rand() % (b - a + 1);
		if (x % 2 == 0) { //만약 랜덤 값이 짝수면
			return x;
		}
		else { //만약 랜덤 값이 홀수면
			if (x + 1 > b) { //랜덤값+1이 주어진 범위를 넘으면 
				return x - 1; //랜덤값-1
			}
			else {
				return x + 1; //랜덤 값 + 1
			}
		}
	}
	else if (c == 'O') { //홀수를 출력해야 한다면...
		x = a + rand() % (b - a + 1);
		if (x % 2 == 1) { //만약 랜덤 값이 홀수면
			return x;
		}
		else { //만약 랜덤 값이 짝수면
			if (x + 1 > b) { //랜덤값+1이 주어진 범위를 넘으면 
				return x - 1; //랜덤값-1
			}
			else {
				return x + 1; //랜덤 값 + 1
			}
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	SelectableRandom r;
	char c;
	cout << "홀수(O)/짝수(E)를 입력해주세요>> ";
	cin >> c;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(c); //0부터 RNAD_MAX까지의 홀수
		cout << n << ' ';
	}
	cout << endl;
	cout << endl;

	cout << "홀수(O)/짝수(E)를 입력해주세요>> ";
	cin >> c;
	int a = 2, b = 10; //처음수와 끝수
	cout << "-- " << a << "에서 " << b << "까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(a, b, c); //2부터 10사이의 홀수
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}