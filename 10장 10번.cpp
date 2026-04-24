#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

class Nation {
private:
	string nation;
	string capital;
public:
	void setNation(string n) { nation = n; }
	void setCapital(string c) { capital = c; }
	string getNation() { return nation; }
	string getCapital() { return capital; }
};

int main() {
	srand((unsigned)time(NULL));
	vector<Nation> v;
	string s1, s2, s3;
	int n=0;

	Nation n1, n2, n3;
	n1.setNation("대한민국"); n1.setCapital("서울");
	n2.setNation("일본"); n2.setCapital("도쿄");
	n3.setNation("미국"); n3.setCapital("워싱턴");
	v.push_back(n1);
	v.push_back(n2);
	v.push_back(n3);
	//3개 넣고 시작

	while (n != 3) {
		cout << "정보 입력: 1, 퀴즈: 2, 종료:3 >> ";
		cin >> n;
		switch (n) {
		case 1:
			cout << "현재 " << v.size() << "개의 나라가 입력되어 있습니다." << endl;
			cout << "나라와 수도를 입력하세요(no no면 입력 종료)" << endl;
			while (1) {
				bool check = true;
				cout << v.size() + 1 << ">> ";
				cin >> s1 >> s2;
				if (s1 == "no" && s2 == "no") break;
				for (int i = 0; i < v.size(); i++) {
					if (v[i].getNation() == s1) {
						cout << "already exists !!" << endl;
						check = false;
					}
				}
				if (check == true) {
					Nation Na;
					Na.setNation(s1); Na.setCapital(s2);
					v.push_back(Na);
				}
			}
			cout << endl;
 			break;
		case 2:
			while (1) {
				int r = rand() % v.size();
				cout << v[r].getNation() << "의 수도는? ";
				cin >> s3;
				if (s3 == "exit") break;
				if (s3 == v[r].getCapital()) cout << "Correct !!" << endl;
				else cout << "NO !!" << endl;
			}
			cout << endl;
			break;
		case 3:
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}