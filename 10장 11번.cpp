#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Book {
	int year;
	string bookName;
	string writer;
public:
	void setYear(int y) { year = y; }
	void setBookName(string b) { bookName = b; }
	void setWriter(string w) { writer = w; }
	int getYear() { return year; }
	string getBookName() { return bookName; }
	string getWriter() { return writer; }
};

int main() {
	vector<Book> v;
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;
	int year = 0;
	string name, writer;
	while (1) {
		Book book;
		cout << "년도 >> ";
		cin >> year;
		if (year == -1) break;
		else book.setYear(year);

		cout << "책이름 >> ";
		cin.ignore();
		getline(cin, name);
		book.setBookName(name);

		cout << "저자 >> ";
		getline(cin, writer);
		book.setWriter(writer);

		v.push_back(book);
		cout << endl;
	}

	cout << endl << "총 입고된 책은 " << v.size() << "권입니다. " << endl;

	cout << "검색하고자 하는 저자 이름을 입력하세요 >> ";
	cin.ignore();
	getline(cin, name);
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getWriter() == name) {
			cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl << endl;
			count++;
		}
	}
	if (count == 0) cout << "검색한 저자의 책은 입고되지 않았습니다." << endl << endl;

	cout << "검색하고자 하는 년도를 입력하세요 >> ";
	cin >> year;
	count = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getYear() == year) {
			cout << v[i].getYear() << "년도, " << v[i].getBookName() << ", " << v[i].getWriter() << endl;
			count++;
		}
	}
	if (count == 0) cout << "검색한 년도의 책은 입고되지 않았습니다." << endl;

	return 0;
}