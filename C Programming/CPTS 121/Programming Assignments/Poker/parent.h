/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 7 - Poker: 5 Card Draw                     *
* Date: 11/18/2020                                                      *
* Description: This program emulates the game of Poker: 5 Card Draw.    *
************************************************************************/

//Guard Code
#ifndef parent

//Constant Macros
#define _CRT_SECURE_NO_WARNINGS

//Header Files
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//Structs
typedef struct card{
	int faceIndex;
	int suitIndex;
}Card;

typedef struct hand {
	Card hand[5];
}Hand;

//Function Prototypes
void rules();
void initHands(Hand* player, Hand* dealer);
void shuffle(int wDeck[][13]);
void deal(int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* player, int n, int redraw, int who);
int pair(Hand* hand, int *highest);
int twoPair(Hand* hand, int* highest);
int triple(Hand* hand, int* highest);
int straight(Hand hand, int* highest);
int flush(Hand* hand, int* highest);
int quadruple(Hand* hand, int* highest);
void highCard(Hand player, Hand dealer);
#endif