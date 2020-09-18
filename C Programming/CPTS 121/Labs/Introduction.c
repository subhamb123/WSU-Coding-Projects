/*******************************************************************************************
* Programmer: Subham Behera                                                                *
* Class: CptS 121, Fall 2020; Lab Section 21                                               *
* Programming Assignment: Lab1Task1                                                        *
* Date: September 4, 2020                                                                  *
* Description: This program prints out a simple "hello world" message.                     *
*******************************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	printf("Hello World, I am in CptS 121!\n");

    int number1_int = 0, number2_int = 0; // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's
    double number1_float = 0.0, number2_float = 0.0; // reserves two memory blocks for numbers with high precision (floating-point)
    printf("a. enter two integer values: "); // ask the user
    scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the keyboard - %d is for "decimal", i.e. integer
    printf("enter two floating-point values: "); // ask the user
    scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through the keyboard - %lf is for "long float", i.e. double precision numbers
    printf("%d\n", number1_int + number2_int);
    printf("%lf\n", number1_float - number2_float);
    printf("%d\n", number1_int * number1_float);
    printf("integer: %d double: %lf\n", (double) number1_int / number2_int, (double) number1_int / number2_int);
    printf("integer: %d double: %lf\n", number1_int / number2_float, number1_int / number2_float);
    printf("%lf\n", (double)number1_int / number2_int);
    printf("%d\n", (int)number1_float % (int)number2_float);
    printf("%d%d\n", number1_int % 2, number2_int % 2);

    int current = 0, res = 0;
    printf("b. enter integer values for current and resistance\n");
    scanf("%d%d", &current, &res);
    printf("voltage = %d * %d = %d\n", current, res, current * res);

    int voltage = 0, resist = 0;
    printf("c. Enter integer values for voltage and resistance\n");
    scanf("%d%d", &voltage, &resist);
    printf("Power = (%d^2) / %d = %d\n", voltage, resist, voltage * voltage / resist);

    /*int x = 0, y = 0, a = 0, b = 0, c = 0, d = 0;
    printf("d. Enter integer values for x, y, a, b, c, d\n");
    scanf("%d%d%d%d%d%d", &x, &y, &a, &b, &c, &d);
    printf("y = 3 * %d*%d^3 + (1/4) * %d*%d^2 + 10 * %d*%d + (-5) * %d = %d", a, x, b, x, c, x, d, );*/

    double radius = 0;
    printf("e. Enter radius: ");
    scanf("%lf", &radius);
    printf("C = 2*pi*%lf = %lf", radius, 2 * 3.141592653 * radius);

	return 0;
}