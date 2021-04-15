#include "parent.h"

Node* makeNode(Contact newData) {
	Node* pMem = (Node*)malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->pNext = NULL;
		strcpy(pMem->data.email, newData.email);
		strcpy(pMem->data.name, newData.name);
		strcpy(pMem->data.phone, newData.phone);
		strcpy(pMem->data.title, newData.title);
	}

	return pMem;
}

Boolean insertContactInOrder(Node** pList, Contact newData) {
	Boolean success = FALSE;
	Node* pMem = makeNode(newData), * pCur = *pList, * pPrev = NULL;
	if (pMem != NULL) {
		success = TRUE;
		while (pCur != NULL && strcmp(pCur->data.name, newData.name) < 0) {
			pPrev = pCur;
			pCur = pCur->pNext;
		}

		if (pPrev != NULL) {
			pMem->pNext = pCur;
			pPrev->pNext = pMem;
		}
		else {
			pMem->pNext = *pList;
			*pList = pMem;
		}
	}

	return success;
}

Boolean deleteContact(Node** pList, Contact searchContact) {
	Node* pPrev = NULL, * pCur = *pList;
	Boolean success = FALSE;
	while (pCur != NULL && strcmp(pCur->data.name, searchContact.name) != 0) {
		pPrev = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != NULL) {
		success = TRUE;
		if (pPrev != NULL) 
			pPrev->pNext = pCur->pNext;
		else
			*pList = pCur->pNext;

		free(pCur);
	}

	return success;
}

Boolean editContact(Node** pList, Contact searchContact) { //Why was it originally *pList, you can't change the original list
	Node* pCur = *pList;
	char entry[100] = "";
	Boolean success = FALSE;
	while (pCur != NULL && strcmp(pCur->data.name, searchContact.name) != 0) 
		pCur = pCur->pNext;

	if (pCur != NULL) {
		success = TRUE;
		printf("Name found!\n");

		printf("Change name (Enter newline to skip)\n");
		scanf("%s", &entry);
		if (strcmp(entry, "\n") != 0)
			strcpy(pCur->data.name, entry);

		printf("Change phone number (Enter newline to skip)\n");
		scanf("%s", &entry);
		if (strcmp(entry, "\n") != 0)
			strcpy(pCur->data.phone, entry);

		printf("Change email address (Enter newline to skip)\n");
		scanf("%s", &entry);
		if (strcmp(entry, "\n") != 0)
			strcpy(pCur->data.email, entry);

		printf("Change title (Enter newline to skip)\n");
		scanf("%s", &entry);
		if (strcmp(entry, "\n") != 0)
			strcpy(pCur->data.title, entry);
	}

	return success;
}

Boolean loadContacts(FILE* infile, Node** pList) {
	int x = 1;
	Node* pCur = *pList;
	char line[100] = "";
	Boolean success = FALSE;
	Contact newNode = { "", "", "", "" };
	while (pCur != NULL) {
		success = TRUE;

		if (x) {
			x = 0;
			
			fscanf(infile, "%s", &pCur->data.name);
			fscanf(infile, "%s", &pCur->data.phone);
			fscanf(infile, "%s", &pCur->data.email);
			fscanf(infile, "%s", &pCur->data.title);
		}
		
		pCur = pCur->pNext;
		if (fscanf(infile, "%s", &newNode.name) != -1) {
			fscanf(infile, "%s", &newNode.phone);
			fscanf(infile, "%s", &newNode.email);
			fscanf(infile, "%s", &newNode.title);
			pCur->pNext = makeNode(newNode);
		}
	}

	return success;
}

Boolean storeContacts(FILE* outfile, Node* pList) {
	Boolean success = FALSE;
	while (pList != NULL) {
		success = TRUE;
		fprintf(outfile, "Name: %s\nPhone Number: %s\nEmail Address: %s\nTitle: %s\n|\n|\nv\n", pList->data.name, pList->data.phone, pList->data.email, pList->data.title);
		pList = pList->pNext;
	}
	putchar('\n');
	return success;
}

void printList(Node* pList) {
	while (pList != NULL) {
		printf("Name: %s\nPhone Number: %s\nEmail Address: %s\nTitle: %s\n|\n|\nv\n", pList->data.name, pList->data.phone, pList->data.email, pList->data.title); //Why not pList.data.phone
		pList = pList->pNext;
	}
	putchar('\n');
}