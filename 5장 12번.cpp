#include<iostream>
using namespace std;

class Dept {
private:
	int size;
	int* scores;
public:
	Dept(int size) {
		this->size = size;
		scores = new int[size];
	}
	~Dept() { delete [] scores; } //동적할당 해제
	int getSize() { return size; } //배열의 크기를 반환하는 함수
	void read(); //성적을 배열에 입력하는 함수
	bool isOver60(int index); //배열의 원소가 60이 넘는지 판단하는 함수
 };

void Dept::read() {
	cout << size << "개 점수 입력 >> ";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	if (scores[index] > 60) return true;
	else return false;
}

int countPass(Dept& dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}
/* 만약 매개변수를 Dept dept로 작성하면, 객체 dept는 값에 의한 호출로 호출된다.
* 객체를 값에 의한 호출로 가져오면 함수 종료 시 소멸자가 실행되는데, 이때 dept의 scores가 동적할당 해제가 된다.
* main함수 종료시 소멸자가 한 번 더 실행되면서 이미 해제한 scores의 메모리를 한 번 더 해제하기 떄문에 오류가 발생한다.
* 따라서 Dept &dept로 참조 호출을 해주거나 깊은 복사를 실행하는 복사생성자를 만들어야 오류가 발생하지 않는다.
*/

int main() {
	Dept com(10);
	com.read();
	int n = countPass(com);
	cout << "60점 이상은 " << n << "명" << endl;

	return 0;
}