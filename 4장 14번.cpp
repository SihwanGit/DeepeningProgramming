#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

class GamblingGame { //게임 클래스
private:
	int ran[3];
public:
	void setNumber(); //0,1,2 중 하나 생성
	int playGame(string name); //게임 실행
};

void GamblingGame::setNumber() {
	for (int i = 0; i < 3; i++) {
		ran[i] = rand() % 3;
	}
}

int GamblingGame::playGame(string name) {
	setNumber();
	cout << "\t\t" << ran[0] << ' ' << ran[1] << ' ' << ran[2] << ' ';
	if ((ran[0] == ran[1]) && (ran[1] == ran[2])) {
		cout << name << "님 승리";
		return 0; //난수값 3개가 같으면 0을 리턴
	}
	else {
		cout << "아쉽군요." << endl;
		return -1; //난수값이 다르면 -1리턴
	}
}

class Player { //플레이어 클래스
private:
	string name;
	GamblingGame gambling;
public:
	Player() {}
	void setName() { cin >> name; }
	string getName() { return name; }
	int playGame();
};

int Player::playGame() { //갬블링 변수가 private이므로 그곳에 접근하기 위한 맴버 함수
	gambling.setNumber();
	return gambling.playGame(name); //게임 결과를 리턴
}


int main() {
	srand((unsigned)time(NULL));
	cout << "***** 겜블링 게임을 시작합니다. *****" << endl;
	Player player[2];
	cout << "첫번째 선수 이름 >> ";
	player[0].setName();
	cout << "두번째 선수 이름 >> ";
	player[1].setName();
	cout << endl;

	int p1, p2;
	char c;
	cin.ignore(); //입력 버퍼 초기화. 이거 없으면 '\n'이 버퍼에 남아 오류가 발생한다.
	while (1) {
		cout << player[0].getName() << ": <Enter> ";
		cin.get(c); //cin은 '\n'을 인식하지 못함. get이나 getline을 사용해야함.
		while (c != '\n') {
			cout << "<Enter>를 입력해주세요 >> "; //Enter를 입력하지 않으면 입력하게 하기.
			cin.ignore();
			cin.get(c);
		}
		p1 = player[0].playGame();
		if (p1 == 0) { //플레이어 0이 이기면
			break;
		}

		cout << player[1].getName() << ": <Enter> ";
		cin.get(c);
		while (c != '\n') {
			cout << "<Enter>를 입력해주세요 >> "; //Enter를 입력하지 않으면 입력하게 하기.
			cin.ignore();
			cin.get(c);
		}
		p2 = player[1].playGame();
		if (p2 == 0) { //플레이어 1이 이기면
			break;
		}
	}
	cout << endl;
	return 0;
}