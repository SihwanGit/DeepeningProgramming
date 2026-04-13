#include<iostream>

int main() {
	for (int i = 0; i < 10; i++) { //10의 자리
		for (int j = 1; j < 11; j++) { //1의 자리
			std::cout << j + i*10 << "\t";
		}
		std::cout << "\n";
	}
	return 0;
}