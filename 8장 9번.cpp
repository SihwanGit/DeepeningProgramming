#include<iostream>
using namespace std;

class Seat { //하나의 좌석을 다루는 클래스
private:
	string seatName;
	int reservation = 0; //예약 여부 판별, 0이면 아직 예약이 없는 상태, 1이면 예약을 이미 받은 상태
public:
	Seat() { seatName = "---"; }
	void setName(string seatName) { //예약자 이름 설정.
		if (this->seatName != "---") {
			cout << "이미 예약된 자리입니다." << endl; //중복 예약 방지
		} else this->seatName = seatName; 
	} 
	string getName() { return seatName; } //예약자 보기
	void seatReservation() { reservation = 1; } //예약 여부 설정
	void cancel() { reservation = 0; seatName = "---"; } //이름 원상복구, 및 예약 취소
};

class Schedule { //시간 당 좌석 설정 시스템
private:
	Seat s[8]; //좌석 8개 설정
	string time;
public:
	void setTime(string time) { this->time = time; } //시간 저장
	string getTime() { return time; } //시간 반환
	void setReservation(string name, int index) { s[index-1].setName(name); s[index-1].seatReservation(); } //좌석 별 예약
	void cancelReservation(int index) { s[index-1].cancel(); } //좌석 별 예약 취소
	string getName(int index) { return s[index-1].getName(); }
	void printSchedule() { //좌석 예약 정보 출력
		for (int i = 0; i < 8; i++) {
			cout << s[i].getName() << '\t';
		}
		cout << endl;
	}
};

class AirlineBook {
private:
	Schedule s[3];
public:
	void setTime(string time, int index) { s[index].setTime(time); } //시간 설정

	void setSchedule(string name, int time, int index) { //시간과 좌석번호와 이름을 받아 예약
		s[time - 1].setReservation(name, index); //time를 1,2,3으로 입력하므로 -1
	}
	void printTime(int time) { ////해당 시간의 예약 정보 출력
		cout << s[time - 1].getTime() << ":\t";
		s[time - 1].printSchedule();
	}
	void printAllSchedule() { //전체 시간 스케줄 출력
		for (int i = 0; i < 3; i++) {
			s[i].printSchedule();
		}
	}
	void cancleSchedule(string name, int time, int index) {
		if (s[time - 1].getName(index) == name) { //취소하려고 입력한 이름이 해당 좌석의 이름과 같다면.
			s[time - 1].cancelReservation(index); //해당 좌석의 예약을 취소
		}
		else {
			cout << "정보를 잘못 입력하여 예약을 취소할 수 없습니다." << endl;
		}
	}
	
};

int main() {
	cout << "***** 한성항공에 오신 것을 환영합니다 *****" << endl << endl;
	int n = 0, t, i; //n은 선택지, t는 시간, i는 좌석번호 
	string name; //예약자의 이름
	AirlineBook a;
	a.setTime("07시", 0);
	a.setTime("12시", 1);
	a.setTime("17시", 2);

	while (n != 4) {
		cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
		cin >> n;
		switch (n) {
		case 1: //예약
			cout << "07시:1, 12시:2, 17시:3 >> ";
			cin >> t;
			a.printTime(t);
			cout << "좌석 번호 >> ";
			cin >> i;
			cout << "이름 입력 >> ";
			cin >> name;
			a.setSchedule(name, t, i);
			cout << endl;
			break;
		case 2: //취소
			cout << "07시:1, 12시:2, 17시:3 >> ";
			cin >> t;
			a.printTime(t);
			cout << "좌석 번호 >> ";
			cin >> i;
			cout << "이름 입력 >> ";
			cin >> name;
			a.cancleSchedule(name, t, i);
			cout << endl;
			break;
		case 3: //전체 출력
			a.printAllSchedule();
			cout << endl;
			break;
		case 4: //종료
			cout << "예약 시스템을 종료합니다." << endl;
			break;
		default: //에러 처리
			cout << "다시 입력해주세요 " << endl;
			break;
		}
	}


	return 0;
}