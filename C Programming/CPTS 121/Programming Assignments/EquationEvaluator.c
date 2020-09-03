/*
	Subham Behera
	9/1/2020
	Description: This program evaluates various equations with user input.
*/

//Constant Macros
#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592653

//Header Files
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	//Character Encoding
	int plainText = 0, shiftInt = 0; //Variables
	char temp = '\0';
	printf("Enter a letter and as shifting factor\n"); //Displays information
	scanf("%c%d", &temp, &shiftInt); //Takes in character and integer input from user
	plainText = (int)temp; //Converts character to integer                                                Using an integer variable at a character placeholder will automatically search for the corresponding ASCII character of that decimal number
	printf("Character encoding: encoded_character = (plaintext_character %c \'a\') + \'A\' %c shift_int = (\'%c\' - \'a\') + \'A\' - %d = %d = %c\n\n", '-', '-', plainText, shiftInt, (plainText - (int)'a') + (int)'A' - shiftInt, (char)((plainText - (int)'a') + (int)'A' - shiftInt));
	
	//Total Series Resistance
	int serRes1 = 0, serRes2 = 0, serRes3 = 0; //Stores numbers without decimals
	printf("Please enter integer values of 3 resistors connected in series\n");
	scanf("%d%d%d", &serRes1, &serRes2, &serRes3);
	printf("Total series resistance: resistance_series = R1+R2+R3 = %d + %d + %d = %d\n\n", serRes1, serRes2, serRes3, serRes1 + serRes2 + serRes3);

	//Sales Tax
	double tax = 0, cost = 0; //Stores numbers with decimals
	printf("Enter sales tax rate: ");
	scanf("%lf", &tax); //Accepts long float from user
	printf("Enter item cost: ");
	scanf("%lf", &cost);
	printf("Sales Tax: total_sales_tax = sales_tax_rate * item_cost = %lf * $%.2f = $%.2f\n\n", 0.01* tax, cost, 0.01*tax*cost);

	//Rectangular Pyramid Volume
	double length = 0, width = 0, height = 0;
	printf("Enter length, width, and height to make rectangular pyramid\n");
	scanf("%lf%lf%lf", &length, &width, &height);
	printf("Volume of a right rectangular pyramid: volume_pyramid = (l * w * h) / 3 = (%lf * %lf * %lf) / 3 = %lf\n\n", length, width, height, (length * width * height) / 3);

	//Total Parallel Resistance
	int parRes1 = 0, parRes2 = 0, parRes3 = 0;
	printf("Please enter integer values of 3 resistors connected in parallel\n");
	scanf("%d%d%d", &parRes1, &parRes2, &parRes3);
	printf("Total parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %d\n\n", parRes1, parRes2, parRes3, (int) (1 / (1 / (double) parRes1 + 1 / (double) parRes2 + 1 / (double) parRes3))); //The resistance values need to be typecasted so the decimal values get carried all throughout the calculation.

	//Distance Between Two Points
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	printf("Enter first point in the format of x1 y1\n");
	scanf("%lf%lf", &x1, &y1);
	printf("Enter second point in the format of x2 y2\n");
	scanf("%lf%lf", &x2, &y2);
	printf("Distance between two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2) = square root of ((%lf - %lf)^2 + (%lf - %lf)^2) = %lf\n\n", x1, x2, y1, y2, sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))); //sqrt and pow only available with math header file

	//General Equation
	double y = 0, z = 0,  x = 0;
	int a = 0;
	printf("Enter values of y, z, x, and a (has to be odd). All but a are doubles.");
	scanf("%lf%lf%lf%d", &y, &z, &x, &a);
	printf("General equation: y = y / (3/17) - z + x / (a %c 2) + PI = %lf / (3/17) - %lf + %lf / (%d %c 2) + PI = %lf", '%', y, z, x, a, 37, y / ((double)3 / (double)17) - z + x / (a % 2) + PI); //The PI macros is used here. It gets replaced with the number value

	return 0;
}