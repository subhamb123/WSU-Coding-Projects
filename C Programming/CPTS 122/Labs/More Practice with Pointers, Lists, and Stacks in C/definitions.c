#include "parent.h"

char* copyStrToHeap(char* pStr) {
	char* pMem = (char*)malloc(strlen(pStr) * sizeof(char));

	if (pMem != NULL)
		strncpy(pMem, pStr, strlen(pStr) + 1);

	return pMem;
}

Node* mergeLists(const Node** const l1, const Node** const l2, int order) {
	Node* merged = (Node*)malloc(sizeof(Node)), * c1 = *l1, *c2 = *l2, *start = merged;
	if (order) {
		if (c1 != NULL && c2 != NULL) {
			if (c1->data < c2->data) {
				merged->data = c1->data;
				c1 = c1->pNext;
			}
			else {
				merged->data = c2->data;
				c2 = c2->pNext;
			}
		}
		while (c1 != NULL && c2 != NULL) {
			Node* pMem = (Node*)malloc(sizeof(Node));
			if (c1->data < c2->data) {
				pMem->data = c1->data;
				c1 = c1->pNext;
			}
			else {
				pMem->data = c2->data;
				c2 = c2->pNext;
			}
			pMem->pNext = NULL;
			merged->pNext = pMem;
			merged = merged->pNext;
		}
		while (c1 != NULL) {
			Node* pMem = (Node*)malloc(sizeof(Node));
			pMem->data = c1->data;
			pMem->pNext = NULL;
			merged->pNext = pMem;
			merged = merged->pNext;
			c1 = c1->pNext;
		}
		while (c2 != NULL) {
			Node* pMem = (Node*)malloc(sizeof(Node));
			pMem->data = c2->data;
			pMem->pNext = NULL;
			merged->pNext = pMem;
			merged = merged->pNext;
			c2 = c2->pNext;
		}
	}
	else {
		if (c1 != NULL && c2 != NULL) {
			if (c1->data > c2->data) {
				merged->data = c1->data;
				c1 = c1->pNext;
			}
			else {
				merged->data = c2->data;
				c2 = c2->pNext;
			}
		}
		while (c1 != NULL && c2 != NULL) {
			Node* pMem = (Node*)malloc(sizeof(Node));
			if (c1->data > c2->data) {
				pMem->data = c1->data;
				c1 = c1->pNext;
			}
			else {
				pMem->data = c2->data;
				c2 = c2->pNext;
			}
			pMem->pNext = NULL;
			merged->pNext = pMem;
			merged = merged->pNext;
		}
		while (c1 != NULL) {
			Node* pMem = (Node*)malloc(sizeof(Node));
			pMem->data = c1->data;
			pMem->pNext = NULL;
			merged->pNext = pMem;
			merged = merged->pNext;
			c1 = c1->pNext;
		}
		while (c2 != NULL) {
			Node* pMem = (Node*)malloc(sizeof(Node));
			pMem->data = c2->data;
			pMem->pNext = NULL;
			merged->pNext = pMem;
			merged = merged->pNext;
			c2 = c2->pNext;
		}
	}

	return start;
}

void printList(const Node** const pList) {
	Node* pCur = *pList;
	while (pCur != NULL) {
		printf("Data: %d --> ", pCur->data);
		pCur = pCur->pNext;
	}
	putchar('\n');
}