/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 5 - The Game of Yahtzee                    *
* Date: 10/16/2020                                                      *
* Description: This program emulates the game of Yahtzee.               *
************************************************************************/

//Guard Code
#ifndef parent

//Constant Macros
#define _CRT_SECURE_NO_WARNINGS

//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

//Function Prototypes
int roll_die();
void combinations();
int* selection_sort(int list[], int size);
void delay(int x);
void rules();

#endif 