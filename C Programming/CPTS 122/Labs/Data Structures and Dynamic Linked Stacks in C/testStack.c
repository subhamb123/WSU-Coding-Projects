#include "testStack.h"

void testPush(Stack* s) {
	double numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; i++) 
		push(s, &numbers[i]);

	if (s->pTop->data == 10)
		puts("Push successful as first node has data value of 10");

	Node* pCur = s->pTop;
	while(pCur != NULL) {
		printf("%lf ", pCur->data);
		pCur = pCur->pNext;
	}
	puts("\n");
}

void testPop(Stack* s) {
	pop(s);
	pop(s);

	if (s->pTop->data == 8)
		puts("Two pops successful as first node has data value of 8");

	Node* pCur = s->pTop;
	while (pCur != NULL) {
		printf("%lf ", pCur->data);
		pCur = pCur->pNext;
	}
	puts("\n");
}

void testPeek(Stack* s) {
	if(peek(s) == 8)
		puts("Peek successful as first node has data value of 8\n");
}

void testIsEmpty(Stack* s) {
	if(!isEmpty(s))
		puts("isEmpty successful as first node isn't null and function returned 0\n");

	for (int i = 0; i < 8; i++)
		pop(s);

	if (isEmpty(s))
		puts("isEmpty successful as first node is null and function returned 1\n");
}