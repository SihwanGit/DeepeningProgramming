#include<iostream>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(NULL)); } //seed
	static int nextInt(int min = 0, int max = 32767); //min과 max사이의 난수
	static char nextAlpgabet();
	static double nextDouble(); //0보다 크거나 같고 1보다 적은 랜덤실수리턴
};

int Random::nextInt(int min, int max) {
	return min + rand() % (max - min + 1);
}

char Random::nextAlpgabet() {
	int x = rand() % 2;
	int c = rand() % 26;
	if (x == 0)
		return 65 + c;
	else
		return 97 + c;
}

double Random::nextDouble() {
	return (double)rand()/32767;
}

int main() {
	Random::seed();
	int min = 0, max = 100, size = 10;
	int x[10];
	char y[10];
	double z[10];

	cout << min << "에서 " << max << "까지 랜덤한 정수 " << size << "개를 출력합니다." << endl;
	for (int i = 0; i < size; i++)
		x[i] = Random::nextInt(min, max);
	for (int i = 0; i < size; i++)
		cout << x[i] << ' ';
	cout << endl << endl;

	cout << "알파벳을 랜덤하게 " << size << "개를 출력합니다." << endl;
	for (int i = 0; i < size; i++)
		y[i] = Random::nextAlpgabet();
	for (int i = 0; i < size; i++)
		cout << y[i] << ' ';
	cout << endl << endl;

	cout << "랜덤한 실수를 " << size << "개 출력합니다." << endl;
	for (int i = 0; i < size; i++)
		z[i] = Random::nextDouble();
	for (int i = 0; i < size/2; i++)
		cout << z[i] << '\t';
	cout << endl;
	for (int i = 0; i < size / 2; i++)
		cout << z[i + size / 2] << '\t';
	cout << endl;

	return 0;
}