#include<iostream>
using namespace std;

int main() {
	cout << "i" << '\t' << "n" << '\t' << "refn" << endl;
	int i = 1;
	int n = 2;
	int& refn = n; //n과 refn의 주소가 동일한 것을 알 수 있다.
	n = 4;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;
	//refn이 증가하자 n도 함께 증가한 것을 볼 수 있다.

	refn = i;
	refn++;
	cout << i << '\t' << n << '\t' << refn << endl;

	int* p = &refn;
	*p = 20;
	cout << i << '\t' << n << '\t' << refn << endl;

	return 0;
}