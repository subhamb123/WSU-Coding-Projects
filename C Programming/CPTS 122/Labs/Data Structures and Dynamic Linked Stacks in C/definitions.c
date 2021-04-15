#include "parent.h"

Node* makeNode(double* pNewData) {
	Node* pMem = (Node*)malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->data = *pNewData;
		pMem->pNext = NULL;
	}
	
	return pMem;
}

int push(Stack* pStack, double* pNewData) {
	int success = 0;
	Node* pMem = makeNode(pNewData);
	if (pMem != NULL) {
		success = 1;
		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}

	return success;
}

void pop(Stack* pStack) {
	Node* pTemp = pStack->pTop;
	pStack->pTop = pStack->pTop->pNext;
	free(pTemp);
}

double peek(Stack* pStack) {
	return pStack->pTop->data;
}

int isEmpty(Stack* pStack) {
	return pStack->pTop == NULL;
}

hStack initStack() {
	hStack st;
	st.top = NULL;
	return st;
}

void hpush(hStack* s, int t) {
	hNode* n1 = (hNode*)malloc(sizeof(hNode));
	n1->value1 = t;
	n1->nxt = s->top;
	s->top = n1;
}

int hpop(hStack* s) {
	hNode* n2 = s->top;
	s->top = n2->nxt;
	char ch = n2->value1;
	free(n2);
	return ch;
}

void display(hStack* st) {
	hNode* s = st->top;
	while (s != NULL) {
		printf("%d ", s->value1);
		s = s->nxt;
	}
	printf("\n");
}