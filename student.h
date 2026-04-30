#pragma once
#pragma once
#include "player.h"

//아래의 코드만 수정할것.
class Student : public Player {
private:
	int myCardValue;			//현재 뽑은 값들의 합
	int cardValueCount[13];		//특정 값을 가진 카드들의 '잔량'을 나타내는 배열
	int highValue;				//나를 버스트 시키는 값보다 높은 값들의 잔량 합
	int restCount;				//남은 카드의 잔량
	int cardDeck;				//카드 덱 수
	int dealerValue;			//딜러의 점수
	double myBustRate;			//버스트 될 확률
	double dealerBustRate;		//딜러의 버스트 될 확률
	string name = "2021111935 김시환";
public:

	Student() { //기본 생성자
		highValue = 0;
		dealerValue = 0;
		for (int i = 0; i < 13; i++) {
			cardValueCount[i] = cardDeck * 4; //남은 카드 장수 = deck * 4 (한 덱 당 같은 값을 가진 카드가 4장이므로)
		}
		restCount = cardDeck * 4 * 13; //모든 카드의 총합
		myBustRate = dealerBustRate = 0; //버스트율 초기화
	}

	//어떤 행동을 할지 반환하는 매소드, HIT = 카드를 계속 받겠다. STAND = 카드 받기를 멈추겠다.
	Action checkAction() {

		//나의 버스트율을 구하는 코드
		int i = 21 - myCardValue; //i는 21까지의 남은 득점
		if (i >= 10) { 
			myBustRate = 0; 
		}
		else {
			for (int j = i; j < 13; j++) {
				highValue += cardValueCount[j]; //뽑으면 안되는 카드들의 합
				myBustRate = highValue / restCount; //내가 bust될 확률
			}
		}

		//HIT / STAND 결정
		if (myCardValue >= 17) { //대략 25% 확률.
			if (dealerValue > myCardValue) return Action::HIT; //근데 상대가 나보다 크면 HIT
			else return Action::STAND; //그렇지 않다면 안전빵으로 STAND
		}
		if (myCardValue <= 11) { //딜러와 무관하게 무조건 HIT
			return Action::HIT;
		}
		else { //12, 13, 14, 15, 16
			if (dealerValue > myCardValue) return Action::HIT; //상대가 더 높으면 어차피 지므로 HIT
			if (myBustRate > dealerBustRate) return Action::STAND; //내가 BUST할 확률이 더 높으니까 STAND
			else { return Action::HIT; } //딜러가 BUST할 확률이 더 높으니 HIT

		}
	}

	string getName() { //이름 반환
		return name;
	}

	double dealerBust(Card card) { //딜러의 값에 따른 버스트율을 반환하는 함수
		int v = card.getValue();
		switch (v) {
		case 1:
			return 11.7;
			break;
		case 2:
			return 35.3;
			break;
		case 3:
			return 37.6;
			break;
		case 4:
			return 40.3;
			break;
		case 5:
			return 42.9;
			break;
		case 6:
			return 42.1;
			break;
		case 7:
			return 26.0;
			break;
		case 8:
			return 23.9;
			break;
		case 9:
			return 23.4;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
			return 21.4;
			break;
		}
	}

	void notifyDealerCard(Card card) { //딜러가 받은 카드가 뭔지 알 수 있는 매소드
		int index = card.getValue();
		cardValueCount[index - 1]--; //덱에 남은 해당 카드 감소
		restCount--; //전체 잔량 감소
		dealerBustRate = dealerBust(card);

		if (card.getValue() == 1) { //딜러 점수 계산
			dealerValue += 11;
		}
		else if (card.getValue() <= 10) {
			dealerValue += card.getValue();
		}
		else {
			dealerValue += 10;
		}
	}

	void notifyOtherPlayerCard(Card card) { //다른 플레이어가 받은 카드가 뭔지 알 수 있는 매소드
		int index = card.getValue();
		cardValueCount[index - 1]--; //덱에 남은 해당 카드 감소
		restCount--; //전체 잔량 감소
	}

	void notifyMyCard(Card card) { //내가 받은 카드가 뭔지 알 수 있는 매소드
		int i = 21 - myCardValue, index = card.getValue();
		if (card.getValue() > 10) myCardValue += 10; // 11, 12, 13은 10으로 통일
		else if ((i >= 11) && (card.getValue() == 1)) { //1도 예외처리
			myCardValue += 11; //1을 뽑았는데, 11을 적용시킬 수 있다면 11을 더함. 그렇지 않다면 1을 더함.
		}
		else myCardValue += card.getValue();
		cardValueCount[index - 1]--; //덱에 남은 해당 카드 감소
		restCount--; //전체 잔량 감소
	}

	//딜러가 사용하는 카드 더미를 새로 만들어낼 때 몇개의 플레잉 카드로 만들어졌는지 알려주는 매소드
	void notifyCardReset(int cardDeck) {
		this->cardDeck = cardDeck;
	}

	void notifyCompletedRound() { //한번의 라운드가 끝났음을 알려주는 매소드
		myCardValue = 0;
		highValue = 0;
		dealerValue = 0;
		for (int i = 0; i < 13; i++) {
			cardValueCount[i] = 4 * cardDeck; //잔량 초기화
		}
		restCount = 4 * cardDeck * 13; //잔량 총합 초기화
		myBustRate = dealerBustRate = 0; //버스트율 초기화
	}
};