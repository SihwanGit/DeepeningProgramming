#include<iostream>
using namespace std;

class Histogram {
private:
	string str; //문자열
	int length = 0; //문자열 길이
	int alpha[26] = { 0 }; //알파벳 개수 저장
public:
	Histogram(string str);
	void put(string str);
	void putc(char c);
	void print();
};

Histogram::Histogram(string str) {
	this->str = str + '\n';
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= 97)&&(str[i] < 123)) { //만약에 소문자면
			length++;
			alpha[str[i] - 97]++;
		}
		else if ((str[i] >= 65) && (str[i] < 91)) { //만약에 대문자면
			length++;
			alpha[str[i] - 65]++;
		}
	}
}

void Histogram::put(string str) {
	this->str += str;
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= 97) && (str[i] < 123)) { //만약에 소문자면
			length++;
			alpha[str[i] - 97]++;
		}
		else if ((str[i] >= 65) && (str[i] < 91)) { //만약에 대문자면
			length++;
			alpha[str[i] - 65]++;
		}
	}
}

void Histogram::putc(char c) {
	str += c;
	if ((c >= 97) && (c < 123)) { //만약에 소문자면
		length++;
		alpha[c - 97]++;
	}
	else if ((c >= 65) && (c < 91)) { //만약에 대문자면
		length++;
		alpha[c - 65]++;
	}
}

void Histogram::print() {
	cout << str << endl << endl;
	cout << "총 알파벳 수 " << length << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 97) << "(" << alpha[i] << ") : ";
		for (int j = 0; j < alpha[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}

}

int main() {
	string str;
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");

	elvisHisto.print();

	return 0;
}