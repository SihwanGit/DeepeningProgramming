#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> sv;
	string name;

	cout << "이름을 5개 입력하라" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">>";
		getline(cin, name);
		sv.push_back(name);
	}

	name = sv.at(0); //sv[0]도 가능
	for (int i = 1; i < sv.size(); i++) {
		if (name < sv[i]) name = sv[i];
	}
	cout << "사전에서 가장 뒤에 나오는 이름은 " << name << endl;
 
	return 0;
}