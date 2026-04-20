#include<iostream>
using namespace std;

class Printer {
private:
	string model; //모델명
	string manufacturer; //제조사
	int printCount; //매수
	int availableCount; //잔량
public:
	Printer(string mo, string mf, int avail) {
		model = mo;
		manufacturer = mf;
		availableCount = avail;
	}
	void print() {
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, ";
	}
	void set(string model, string manufacturer, int availableCount) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->availableCount = availableCount;
	}
	void setPrint(int pages) {
		printCount = pages;
		availableCount -= printCount;
	}
	int getAvailable() { //출력 가능한 매수 반환
		return availableCount;
	}
};

class InkJetPrinter : public Printer {
private:
	int availableInk;
public:
	InkJetPrinter(string mo, string mf, int avail, int ink) : Printer(mo, mf, avail) { availableInk = ink; } //초기화 생성자
	void printInkJet() { //프린터의 정보와 남은 잉크를 출력하는 함수
		cout << "잉크젯: ";
		print();
		cout << "남은 잉크 " << availableInk << endl;
	}
	void selectInkJet(int pages) {
		if (pages > getAvailable()) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		else if (availableInk < pages) cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		else {
			cout << "프린트하였습니다." << endl;
			availableInk -= pages; //잉크는 매수만큼 소모된다.
			setPrint(pages);
		}
	}
};

class LaserPrinter : public Printer {
private:
	int availableToner;
public:
	LaserPrinter(string mo, string mf, int avail, int toner) : Printer(mo, mf, avail) { availableToner = toner; } //초기화 생성자
	void printLaser() { //프린터의 정보와 남은 토너를 출력하는 함수
		cout << "레이저: ";
		print();
		cout << "남은 토너 " << availableToner << endl;
	}
	void selectLaser(int pages) {
		if (pages > getAvailable()) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		else if (availableToner <= 0) cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		else {
			cout << "프린트하였습니다." << endl;
			availableToner--; //토너는 매수에 관계없이 1씩 소모된다.
			setPrint(pages);
		}
	}
};

int main() {
	int p, c; //p는 프린터 설정, c는 매수 설정
	LaserPrinter laser("SCX-6x45", "삼정전자", 3, 20); //LaserPrinter 객체
	InkJetPrinter ink("Officejet V40", "HP", 5, 10); //InkJetPrinter 객체

	cout << "현재 작동 중인 2 대의 프린터는 아래와 같다" << endl;
	ink.printInkJet();
	laser.printLaser();

	while (1) {
		cout << endl;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
		cin >> p;
		switch (p) {
		case 1:
			cin >> c;
			ink.selectInkJet(c);
			ink.printInkJet();
			laser.printLaser();
			break;
		case 2:
			cin >> c;
			laser.selectLaser(c);
			ink.printInkJet();
			laser.printLaser();
			break;
		default:
			break;
		}
		cout << "계속 프린트 하시겠습니까(y/n) >> ";
		char i;
		cin >> i;
		if (i != 'n' && i != 'y') { //엉뚱한걸 입력하면 제대로 입력할 떄까지 반복
			while (i != 'n' && i != 'y') {
				cout << "다시 입력해주세요(y/n) >> ";
				cin >> i;
			}
		}
		if (i == 'n') break; //n을 입력하면 프로그램 종료
		else if (i == 'y') continue; //y를 입력하면 계속 반복
	}
	return 0;
}
