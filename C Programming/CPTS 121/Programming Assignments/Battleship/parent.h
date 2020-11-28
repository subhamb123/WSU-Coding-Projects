/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 6 - Basic Game of Battleship               *
* Date: 11/1/2020                                                       *
* Description: This program emulates the game of Battleship.            *
************************************************************************/

//Guard Code
#ifndef parent

//Constant Macros
#define _CRT_SECURE_NO_WARNINGS
#define rows 10
#define columns 10

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//Function Prototypes
int welcome_screen();
void init_board(char board[rows][columns]);
void print_board(const char board[rows][columns], int x);
void manually_place_ships_on_board(char pBoard[rows][columns]);
void randomly_place_ships_on_board(char board[rows][columns]);
void delay(int x);
int* selection_sort(int list[], int size);

//Struct
typedef struct stats {
	int hits;
	int misses;
	int shots;
	double ratio;
	int win;
} Stats;

#endif