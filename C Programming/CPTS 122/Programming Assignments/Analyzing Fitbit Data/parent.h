/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 1 - Analyzing Fitbit Data                  *
* Date: 1/24/2021                                                       *
* Description: This program analyzes fitbit data.                       *
************************************************************************/

//Guard Code
#ifndef parent

//Constant Macros
#define _CRT_SECURE_NO_WARNINGS

//Header Files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Structs & Enumerations
typedef enum sleep{
    NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
} FitbitData;

//Function Prototypes
void initData(FitbitData* arr, FILE* infile);

#endif