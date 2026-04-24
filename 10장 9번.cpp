#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	
	while (1) {
		int n;
		double sum = 0, avg;
		cout << "정수를 입력하세요(0을 입력하면 종료) >> ";
		cin >> n;
		if (n == 0) break;
		v.push_back(n);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		avg = sum / v.size();
		cout << endl << "평균 = " << avg << endl << endl;
	}

	return 0;
}