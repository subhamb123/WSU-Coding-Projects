#ifndef parent

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct profile{
	char name[100];
	char plan;
	int talk_minutes;
	int data_MB;
	double charges;
} Profile;

void initProfile(Profile* customers);

#endif