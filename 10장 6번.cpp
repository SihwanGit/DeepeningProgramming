#include<iostream>
using namespace std;

template <class T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	int count = 0;
	int i, j;
	for (i = 0; i < sizeSrc; i++) {
		for (j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				count++; //겹치는 숫자의 개수
				src[i] = 0; //만약 src와 dest에 겹치는 수가 있다면 src를 엉뚱한 값으로 변환해주기
			}
		}
	}
	retSize = sizeSrc - count;
	T* x = new T[retSize];
	j = 0;
	for (int i = 0; i < sizeSrc; i++) {
		if (src[i] == 0) { //만약 src가 32767이면 x에 복사하지 않고 패스

		}
		else {
			x[j++] = src[i];
		}
	}

	return x;
}

int main() {
	int n1, n2, retSize = 0;

	cout << "원본 배열 src의 크기를 입력하세요 >> ";
	cin >> n1;
	int* src = new int[n1];
	cout << "입력하신 크기만큼 src의 원소들을 입력해주세요(0을 제외하고) >> ";
	for (int i = 0; i < n1; i++) cin >> src[i];

	cout << endl << "빼고자 하는 배열 minus의 크기를 입력하세요 >> ";
	cin >> n2;
	int* minus = new int[n2];
	cout << "입력하신 크기만큼 minus의 원소들을 입력해주세요(0을 제외하고) >> ";
	for (int i = 0; i < n2; i++) cin >> minus[i];

	int* x = remove(src, n1, minus, n2, retSize);
	cout << endl << "src에서 minus를 제외한 배열: ";
	for (int i = 0; i < retSize; i++) {
		cout << x[i] << ' ';
	}
	cout << endl;

	delete[] src;
	delete[] minus;
	delete[] x;

	return 0;
}