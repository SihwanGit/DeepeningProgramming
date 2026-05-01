#include<stdio.h>
#include"melong.h" //<>가 아니다.
#define _CRT_SECUER_NO_WARNINGS 


typedef struct student {
	int sid;
	char name[20];
	char gender;
} STU;

typedef struct _node {
	int item;
	struct _node* next;
}node ;

int main() {
	STU std[3];

	for (int i = 0; i < 3; i++)
		scanf_s("%d, %s, %c", &std[i].sid, std[i].name, &std[i].gender);
	for (int i = 0; i < 3; i++)
		printf("%d, %s, %c", std[i].sid, std[i].name, std[i].gender);

	melong();


	node n0, n1, n2;
	n0.item = 10;
	n0.next = &n1;
	n1.item = 18;
	n1.next = &n2;
	n2.item = 103;
	n2.next = NULL;
	
	node* p0, * p1, * p2;
	p0 = &n0;
	p1 = &n1;
	p2 = &n2;

	node* ptr;
	ptr = p0;
	while (ptr != NULL) {
		printf("%d\n", ptr->item);

	}

	printf("%d %d %d\n", p0->item, p1->item, p2->item);
	

	return 0;
}
