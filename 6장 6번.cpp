#include<iostream>
using namespace std;

class ArrayUtility2 {
	static int* mem1; //이거 static으로 안하면 사용불가능
	static int* mem2;
public:
	static int* concat(int s1[], int s2[], int size);
	
	//s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적생성하여 리턴
	//리턴하는 배열의 크기는 retsize에 전달. retsize가 0인 경우 NULL 리턴
	static int* remove(int s1[], int s2[], int size, int& retsize);
	~ArrayUtility2() { delete mem1; delete mem2; }
};

int* ArrayUtility2::mem1; //static 맴버 변수는 전역 공간에 변수의 공간을 할당받는 선언문이 추가적으로 필요.
int* ArrayUtility2::mem2;

int* ArrayUtility2::concat(int s1[], int s2[], int size) {
	mem1 = new int[2 * size];
	for (int i = 0; i < size; i++) mem1[i] = s1[i];
	for (int i = 0; i < size; i++) mem1[i + size] = s2[i];
	return mem1;
}

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retsize) {
	int count = 0; //겹치는 원소의 개수
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (s1[i] == s2[j]) {
				count++;//원소가 겹치면 카운트
				s1[i] = 32767; //이거 쓰면 오류 생기는 이유는 얘를 쓰면 s1[3] = 0이돼서 s2[3]이랑 또 겹쳐서 count++된거임.
				//그래서 count가 size보다 커져서 음수크기를 동적할당받아 오류가 생기는 것
				//s1[i] = 32767로 토큰값을 변경해버림.
			}
		}
	}

	retsize = size - count; //재생성한 배열의 크기는 size - count
	if (retsize == 0) { 
		return NULL; 
	}
	else {
		mem2 = new int[retsize];
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (s1[i] != 32767) mem2[j++] = s1[i]; //s1배열의 NULL이 아닌 원소만 mem2배열에 할당
		}
		return mem2;
	}
}

int main() {
	int x[5], y[5];
	int size=5, retsize=0;
	cout << "정수 " << size << "개를 입력하라. 배열 x에 삽입한다 >> ";
	for (int i = 0; i < size; i++) cin >> x[i];
	cout << "정수 " << size << "개를 입력하라. 배열 y에 삽입한다 >> ";
	for (int i = 0; i < size; i++) cin >> y[i];
	
	cout << endl << "합친 정수 배열을 출력한다." << endl;
	int* s = ArrayUtility2::concat(x, y, size);
	for (int i = 0; i < 2 * size; i++) cout << s[i] << ' ';
	cout << endl << endl;

	s = ArrayUtility2::remove(x, y, size, retsize);
	cout << "배열 x[]에서 y[]를 뺸 결과를 출력한다. 개수는 "  << retsize << endl;
	if (s) { //s가 NULL이 아니면
		for (int i = 0; i < retsize; i++) cout << s[i] << ' ';
		cout << endl;
	}
	else {
		cout << "배열은 NULL입니다." << endl;
	}
	return 0;
}