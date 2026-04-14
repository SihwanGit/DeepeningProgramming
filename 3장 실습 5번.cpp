#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Random {
public:
	int next() { return rand() % RAND_MAX;} //0부터 RNAD_MAX까지의 난수 리턴
	int nextInRange(int a, int b) { return  a + rand() % (b-a+1);} //a부터 b까지의 난수 리턴
};

int main() {
	srand((unsigned)time(NULL));
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); //0부터 RNAD_MAX까지의 난수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 4까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); //2부터 4사이의 난수
		cout << n << ' ';
	}
	cout << endl;

	return 0;
}