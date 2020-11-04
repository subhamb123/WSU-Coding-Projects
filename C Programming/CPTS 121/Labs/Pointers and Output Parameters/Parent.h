#ifndef parent

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void charges(double* charge, double* average, FILE* infile);
double round_money(double charge);

void revenue(double* R, int t);
void predict(int* year, double revenue);

#endif