#ifndef parent

#define parent
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
	double data;
	struct node* pNext;
} Node;

typedef struct stack {
	Node* pTop;
} Stack;

typedef struct nodes {
    int value1;
    struct nodes* nxt;
} hNode;

typedef struct stacks {
    hNode* top;
} hStack;

Node* makeNode(double* pNewData);
int push(Stack* pStack, double* pNewData);
void pop(Stack* pStack);
double peek(Stack* pStack);
int isEmpty(Stack* pStack);

void hpush(hStack* s, int t);
int hpop(hStack* s);
void display(hStack* st);
hStack initStack();

#endif