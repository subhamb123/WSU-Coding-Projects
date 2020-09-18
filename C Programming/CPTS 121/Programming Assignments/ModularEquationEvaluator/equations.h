/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 2 - Modular Equation Evaluator             *
* Date: 9/16/2020                                                       *
* Description: This program evaluates various equations with user input *
*              with a modular approach.                                 *
************************************************************************/

//Constant Macros
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592653

//Header Files
#include <stdio.h>
#include <string.h>
#include <math.h>

//Function Prototypes
int calculate_series_resistance(int r1, int r2, int r3);
double calculate_total_sales_tax(double sales_tax_rate, double item_cost);
double calculate_volume_pyramid(double l, double w, double h);
double calculate_parallel_resistance(int r1, int r2, int r3);
int character_encoding(int plainText, int shiftInt);
double distance_two_points(double x1, double y1, double x2, double y2);
double calculate_general_equation(double y, double z, double x, int a);