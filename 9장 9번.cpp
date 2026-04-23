#include<iostream>
using namespace std;

class Printer {
protected: //맴버 변수들을 protected로 바꿔줌.
	string model; //모델명
	string manufacturer; //제조사
	int printCount; //매수
	int availableCount; //잔량
public:
	Printer(string mo, string mf, int avail) { //생성자
		model = mo;
		manufacturer = mf;
		availableCount = avail;
	}
	virtual void print(int pages) = 0; //pages만큼 출력하는 함수, 가능한 잔량을 출력한 매수만큼 뺸다.
	virtual void show() = 0;
};

class InkJetPrinter : public Printer {
private:
	int availableInk;
public:
	InkJetPrinter(string mo, string mf, int avail, int ink) : Printer(mo, mf, avail) { availableInk = ink; } 
	//초기화 생성자
	void show() { //프린터의 정보와 남은 잉크를 출력하는 함수, show()
		cout << "잉크젯: ";
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, ";
		cout << "남은 잉크 " << availableInk << endl;
	}
	void print(int pages) {
		if (pages > availableCount) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		else if (availableInk < pages) cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
		else {
			cout << "프린트하였습니다." << endl;
			availableInk -= pages; //잉크는 매수만큼 소모된다.
			printCount = pages;
			availableCount -= printCount;
		}
	}
};

class LaserPrinter : public Printer {
private:
	int availableToner;
public:
	LaserPrinter(string mo, string mf, int avail, int toner) : Printer(mo, mf, avail) { availableToner = toner; } 
	//초기화 생성자
	void show() { //프린터의 정보와 남은 토너를 출력하는 함수
		cout << "레이저: ";
		cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장, ";
		cout << "남은 토너 " << availableToner << endl;
	}
	void print(int pages) {
		if (pages > availableCount) cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		else if (availableToner <= 0) cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
		else {
			cout << "프린트하였습니다." << endl;
			availableToner--; //토너는 매수에 관계없이 1씩 소모된다.
			printCount = pages;
			availableCount -= printCount;
		}
	}
};

int main() {
	int p, c; //p는 프린터 설정, c는 매수 설정
	Printer* pp[2];
	pp[0] = new LaserPrinter("SCX-6x45", "삼정전자", 3, 20); //laser 동적할당
	pp[1] = new InkJetPrinter("Officejet V40", "HP", 5, 10); //InkJet 동적할당

	cout << "현재 작동 중인 2 대의 프린터는 아래와 같다" << endl;
	pp[0]->show();
	pp[1]->show();

	while (1) {
		cout << endl;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 >> ";
		cin >> p;
		switch (p) {
		case 1:
			cin >> c;
			pp[1]->print(c);
			pp[1]->show();
			pp[0]->show();
			break;
		case 2:
			cin >> c;
			pp[0]->print(c);
			pp[1]->show();
			pp[0]->show();
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

	for (int i = 0; i < 2; i++) delete pp[i]; //해제는 각각

	return 0;
}