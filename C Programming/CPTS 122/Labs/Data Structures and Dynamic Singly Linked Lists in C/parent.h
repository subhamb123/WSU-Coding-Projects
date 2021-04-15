#ifndef parent

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum boolean {
    FALSE, TRUE
} Boolean;

typedef struct contact {
    char name[50];
    char phone[12];
    char email[50];
    char title[20];
} Contact;

typedef struct node {
    Contact data;
    struct node* pNext;
} Node;

Node* makeNode(Contact newData);
Boolean insertContactInOrder(Node** pList, Contact newData);
Boolean deleteContact(Node** pList, Contact searchContact);
Boolean editContact(Node** pList, Contact searchContact);
Boolean loadContacts(FILE* infile, Node** pList);
Boolean storeContacts(FILE* outfile, Node* pList);
void printList(Node* pList);

#endif