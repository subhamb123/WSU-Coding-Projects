/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 2 - Modular Equation Evaluator             *
* Date: 9/16/2020                                                       *
* Description: This program evaluates various equations with user input *
*              with a modular approach.                                 *
************************************************************************/

//Calls the equations.h header file
#include "equations.h"

int main() {
	//Character Encoding
	int plainText = 0, shiftInt = 0; //Variables
	char temp = '\0';
	printf("Enter a letter and a shifting factor\n"); //Displays information
	scanf("%c%d", &temp, &shiftInt); //Takes in character and integer input from user
	plainText = (int)temp; //Converts character to integer                                                Using an integer variable at a character placeholder will automatically search for the corresponding ASCII character of that decimal number
	printf("Character encoding: encoded_character = (plaintext_character %c \'a\') + \'A\' %c shift_int = (\'%c\' - \'a\') + \'A\' - %d = %d = %c\n\n", '-', '-', plainText, shiftInt, character_encoding(plainText, shiftInt), (char)character_encoding(plainText, shiftInt));

	//Total Series Resistance
	int serRes1 = 0, serRes2 = 0, serRes3 = 0; //Stores numbers without decimals
	printf("Please enter integer values of 3 resistors connected in series\n");
	scanf("%d%d%d", &serRes1, &serRes2, &serRes3);
	printf("Total series resistance: resistance_series = R1+R2+R3 = %d + %d + %d = %d\n\n", serRes1, serRes2, serRes3, calculate_series_resistance(serRes1, serRes2, serRes3));

	//Sales Tax
	double tax = 0, cost = 0; //Stores numbers with decimals
	printf("Enter sales tax rate: ");
	scanf("%lf", &tax); //Accepts long float from user
	printf("Enter item cost: ");
	scanf("%lf", &cost);
	printf("Sales Tax: total_sales_tax = sales_tax_rate * item_cost = %lf * $%.2f = $%.2f\n\n", 0.01 * tax, cost, calculate_total_sales_tax(tax, cost));

	//Rectangular Pyramid Volume
	double length = 0, width = 0, height = 0;
	printf("Enter length, width, and height to make rectangular pyramid\n");
	scanf("%lf%lf%lf", &length, &width, &height);
	printf("Volume of a right rectangular pyramid: volume_pyramid = (l * w * h) / 3 = (%lf * %lf * %lf) / 3 = %.2f\n\n", length, width, height, calculate_volume_pyramid(length, width, height));

	//Total Parallel Resistance
	int parRes1 = 0, parRes2 = 0, parRes3 = 0;
	printf("Please enter integer values of 3 resistors connected in parallel\n");
	scanf("%d%d%d", &parRes1, &parRes2, &parRes3);
	printf("Total parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3) = 1 / (1 / %d + 1 / %d + 1 / %d) = %.2f\n\n", parRes1, parRes2, parRes3, calculate_parallel_resistance(parRes1, parRes2, parRes3)); 

	//Distance Between Two Points
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	printf("Enter first point in the format of x1 y1\n");
	scanf("%lf%lf", &x1, &y1);
	printf("Enter second point in the format of x2 y2\n");
	scanf("%lf%lf", &x2, &y2);
	printf("Distance between two points: distance = square root of ((x1 - x2)^2 + (y1 - y2)^2) = square root of ((%lf - %lf)^2 + (%lf - %lf)^2) = %.2f\n\n", x1, x2, y1, y2, distance_two_points(x1, y1, x2, y2)); 

	//General Equation
	double y = 0, z = 0, x = 0;
	int a = 0;
	printf("Enter values of y, z, x, and a (has to be odd). All but a are doubles.\n");
	scanf("%lf%lf%lf%d", &y, &z, &x, &a);
	printf("General equation: y = y / (3/17) - z + x / (a %c 2) + PI = %lf / (3/17) - %lf + %lf / (%d %c 2) + PI = %.2f\n", '%', y, z, x, a, 37, calculate_general_equation(y, z, x, a));

	return 0;
}