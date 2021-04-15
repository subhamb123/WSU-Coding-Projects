#ifndef parent

#define parent
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* pNext;
} Node;

char* copyStrToHeap(char* pStr);
Node* mergeLists(const Node** const l1, const Node** const l2, int order);
void printList(const Node** const pList);

#endif