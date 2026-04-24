#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

class OpenChallenge {
	string English;
	string Korean;
public:
	void setEnglish(string e) { English = e; }
	void setKorean(string k) { Korean = k; }
	string getEnglish() { return English; }
	string getKorean() { return Korean; }
};

int main() {
	srand((unsigned)time(NULL));
	vector<OpenChallenge> v;
	string ew, kw;
	int check = 0;

	cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;
	while (check != 1) {
		cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료: 그외 키 >> ";
		int n;
		cin >> n;
		switch (n) {
		case 1:
			cout << "영어 단어에 exit를 입력하면 입력 끝" << endl;
			while (1) {
				cout << "영어 >> ";
				cin >> ew;
				if (ew == "exit") break;
				cout << "한글 >> ";
				cin >> kw;
				OpenChallenge oc;
				oc.setEnglish(ew);
				oc.setKorean(kw);
				v.push_back(oc);
			}
			cout << endl;
			break;
		case 2:
			cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료." << endl;
			while (1) {
				int ran[4]; //난수값 4개
				for (int i = 0; i < 4; i++) { //난수를 중복없이 뽑는 코드
					ran[i] = rand() % v.size();
					for (int j = 0; j < i; j++) {
						if (ran[i] == ran[j]) i--;
					}
				}
				int ran2 = rand() % 4;  //난수 중에서 하느를 골라
				cout << v[ran[ran2]].getEnglish() << '?' << endl;

				int sel;
				cout << "(1) " << v[ran[0]].getKorean() << " (2) " << v[ran[1]].getKorean();
				cout << " (3) " << v[ran[2]].getKorean() << " (4) " << v[ran[3]].getKorean() << " :> ";
				cin >> sel; //답 입력
				if (sel <= 0 && sel >= 5) break; //다른 답 입력시 종료
				if (v[ran[sel - 1]].getEnglish() == v[ran[ran2]].getEnglish()) cout << "Excellent !!" << endl << endl;
				else cout << "No. !!" << endl << endl;
			}
			cout << endl;
			break;
		default:
			check = 1;
			cout << endl;
			break;
		}
	}
	cout << "영어 어휘 테스트를 종료합니다." << endl;
	return 0;
}