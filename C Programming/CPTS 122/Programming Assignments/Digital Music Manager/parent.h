/*************************************************************************************
* Programmer: Subham Behera                                                          *
* Class: CptS 122; Lab Section 13                                                    *
* Programming Assignment: PA 3 - Digital Music Manager & Doubly Linked Lists – Part 2*
* Date: 2/14/2021                                                                    *
* Description: This program manages music data with linked lists.                    *
**************************************************************************************/

//Guard Code
#ifndef parent

//Constant Macros
#define parent
#define _CRT_SECURE_NO_WARNINGS

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//Structs

typedef struct duration {
	int minutes;
	int seconds;
} Duration;

typedef struct record {
	char artist[100];
	char album[100];
	char song[100];
	char genre[100];
	Duration length;
	int timesPlayed;
	int rating;
} Record;

typedef struct node {
	Record data;
	struct node* pNext;
	struct node* pPrev;
} Node;

typedef struct list {
	Node* pHead;
} List;

//Function Prototypes
Node* makeNode(const Record* const pNewData);
int insertFront(List* pList, const Record* const pNewData);
int load(FILE* infile, List* pList);
int store(FILE* outfile, List* pList);
void printList(const List* pList);
void displayByArtist(const List* pList, char* artist);
int insert(List* pList, Record* const pNewData);
int delete(List* pList, char* song);
int edit(List* pList, char* artist);
int sort(List* pList, int option);
int rate(List* pList, char* song, int rating);
void play(List* pList, char* song);
void shuffle(List* pList, int *order);
void Exit(FILE* outfile, List* pList);
void delay(int x);

#endif