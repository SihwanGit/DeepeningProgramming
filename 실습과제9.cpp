#include<stdio.h>

int main() {
	int i = 0x324F3A24;
	char* pc;
	pc = (char *)&i;

	printf("0x");
	for (int i = 0; i < 4; i++) {
		printf("%X", *(pc+3-i));
	}
	printf("\n");

	return 0;
}