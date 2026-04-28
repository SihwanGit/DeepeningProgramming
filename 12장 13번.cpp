#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> v;

	ifstream fin("c:\\temp\\words.txt");
	if (!fin) {
		cout << "파일을 열 수 없습니다." << endl;
		return 0;
	}

	string str;
	while (getline(fin, str)) {
		v.push_back(str);
	}
	cout << "... words.txt 파일 로딩 왼료" << endl;
	cout << "검색을 시작합니다. 단어를 입력해주세요." << endl;

	while (1) {
		int count = 0;
		cout << "단어 >> ";
		cin >> str;
		if (str == "exit") break;
		for (int i = 0; i < v.size(); i++) { //v[i] 탐색
			int index = v[i].find(str); //string에서 해당 단어를 맨처음으로 발견한 인덱스를 리턴
			if (index == 0) {
				cout << v[i] << endl; //index = 0이면 입력한 단어로 시작하는 코드
				count++; //발견할 떄마다 count가 증가
		}
		if (count == 0) cout << "발견할 수 없음" << endl; //모든 탐색이 끝났음에도 count = 0이면 발견 실패
		cout << endl;
	}
	cout << "프로그램을 종료합니다..." << endl;
	fin.close();
	return 0;
}