#include "parent.h"

int main() {
	int n1 = 10, n2 = 42;
	int* const p1 = &n1;
	const int* p2 = &n1;
	const int* const p3 = NULL; //Useless as indirection value can't be changed and pointer can't point to anything else
	int* p4 = NULL;

	//p1 = &n2; Constant pointer so can't point to anything else
	*p1 = 41;

	p2 = &n2; 
	//*p2 = 41; Constant integer so indirection can't change it

	if (p4 == p3)
		puts("useless lol");

	puts(copyStrToHeap("1. HelloWorld"));

	puts("2.");
	Node* list1 = (Node*)malloc(sizeof(Node)), * list2 = (Node*)malloc(sizeof(Node)), * list3 = (Node*)malloc(sizeof(Node)), * list4 = (Node*)malloc(sizeof(Node)), * ascending = NULL, * descending = NULL;
	list1->data = 50;
	list1->pNext = (Node*)malloc(sizeof(Node));
	list1->pNext->data = 100;
	list1->pNext->pNext = (Node*)malloc(sizeof(Node));
	list1->pNext->pNext->data = 300;
	list1->pNext->pNext->pNext = NULL;
	list2->data = 75;
	list2->pNext = (Node*)malloc(sizeof(Node));
	list2->pNext->data = 200;
	list2->pNext->pNext = (Node*)malloc(sizeof(Node));
	list2->pNext->pNext->data = 400;
	list2->pNext->pNext->pNext = NULL;

	list3->data = 300;
	list3->pNext = (Node*)malloc(sizeof(Node));
	list3->pNext->data = 100;
	list3->pNext->pNext = (Node*)malloc(sizeof(Node));
	list3->pNext->pNext->data = 50;
	list3->pNext->pNext->pNext = NULL;
	list4->data = 400;
	list4->pNext = (Node*)malloc(sizeof(Node));
	list4->pNext->data = 200;
	list4->pNext->pNext = (Node*)malloc(sizeof(Node));
	list4->pNext->pNext->data = 75;
	list4->pNext->pNext->pNext = NULL;

	ascending = mergeLists(&list1, &list2, 1);
	descending = mergeLists(&list3, &list4, 0);
	printList(&ascending);
	printList(&descending);

	return 0;
}