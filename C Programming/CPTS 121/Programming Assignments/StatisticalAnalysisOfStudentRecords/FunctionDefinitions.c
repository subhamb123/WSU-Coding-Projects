/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 121; Lab Section 21                                       *
* Programming Assignment: PA 3 - Statistical Analysis of Student Records*
* Date: 9/20/2020                                                       *
* Description: This program calculates different things using data in an*
*              input file.                                              *
************************************************************************/

//Calls the Parent.h header file
#include "Parent.h"

//Function Definitions

/****************************************************************
	* Function: read_double()                                   *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Reads one double precision number from the   *
    *              input file.                                  *
	* Input parameters: Infile                                  *
	* Returns: Double number from infile                        *
	* Preconditions: infile must be open programatically        *
	* Postconditions: Double number has been returned           *
	*************************************************************/
double read_double(FILE* infile) {
	double number = 0;
	fscanf(infile, "%lf", &number);
	return number;
}

/****************************************************************
	* Function: read_integer()                                  *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Reads one integer number from the input file.*
	* Input parameters: Infile                                  *
	* Returns: Integer from infile                              *
	* Preconditions: infile must be open programatically        *
	* Postconditions: Integer has been returned                 *
	*************************************************************/
int read_integer(FILE* infile) {
	int number = 0;
	fscanf(infile, "%d", &number);
	return number;
}

/****************************************************************
	* Function: calculate_sum()                                 *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Finds the sum of number1, number2, number3,  *
	*              number4, and number5 and returns the result. *
	* Input parameters: 5 numbers                               *
	* Returns: Sum of the five numbers.                         *
	* Preconditions: 5 numbers                                  *
	* Postconditions: The sum of the five numbers has been      *
	*                 calculated.                               *
	*************************************************************/
double calculate_sum(double number1, double number2, double number3, double number4, double number5) {
	return number1 + number2 + number3 + number4 + number5;
}

/****************************************************************
	* Function: calculate_mean()                                *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Determines the mean through the calculation  *
	*              sum / number and returns the result.         *
	* Input parameters: Sum of numbers and number of numbers.   *
	* Returns: Mean of the numbers                              *
	* Preconditions: Sum of numbers and number of numbers.      *
	* Postconditions: The mean of the numbers has been          *
	*                 calculated.                               *
	*************************************************************/
double calculate_mean(double sum, int number) {
	if (number == 0)
		return -1;
	return sum / (double) number;
}

/****************************************************************
	* Function: calculate_deviation()                           *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Determines the deviation of number from the  *
	*              mean and returns the result.                 *
	* Input parameters: Number of numbers and mean              *
	* Returns: Deviation of the numbers                         *
	* Preconditions: Number of numbers and mean                 *
	* Postconditions: The deviation of the numbers has been     *
	*                 calculated.                               *
	*************************************************************/
double calculate_deviation(double number, double mean) {
	return number - mean;
}

/****************************************************************
	* Function: calculate_variance()                            *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Determines the variance through a calculation*
	* Input parameters: 5 deviations and a number               *
	* Returns: Variance of the numbers                          *
	* Preconditions: 5 deviations and a number                  *
	* Postconditions: The variance of the numbers has been      *
	*                 calculated.                               *
	*************************************************************/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	return (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / (double) number;
}

/****************************************************************
	* Function: calculate_standard_deviation()                  *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Calculates the standard deviation as sqrt    *
	*              (variance) and returns the result.           *
	* Input parameters: Variance of numbers                     *
	* Returns: Standard deviation of numbers                    *
	* Preconditions: Variance of numbers                        *
	* Postconditions: The standard deviation of the numbers     *
	*                 has been calculated.                      *
	*************************************************************/
double calculate_standard_deviation(double variance) {
	return sqrt(variance);
}

/****************************************************************
	* Function: find_max()                                      *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Determines the maximum number out of the five*
	*              input parameters passed into the function.   *
	* Input parameters: 5 numbers                               *
	* Returns: Maximum value of the numbers                     *
	* Preconditions: 5 numbers                                  *
	* Postconditions: The max has been found                    *
	*************************************************************/
double find_max(double number1, double number2, double number3, double number4, double number5) {
	double max = 0;
	if (number1 > max)
		max = number1;
	if (number2 > max)
		max = number2;
	if (number3 > max)
		max = number3;
	if (number4 > max)
		max = number4;
	if (number5 > max)
		max = number5;
	return max;
}

/****************************************************************
	* Function: find_min()                                      *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Determines the minimum number out of the five*
	*              input parameters passed into the function.   *
	* Input parameters: 5 numbers                               *
	* Returns: Minimum value of the numbers                     *
	* Preconditions: 5 numbers                                  *
	* Postconditions: The min has been found                    *
	*************************************************************/
double find_min(double number1, double number2, double number3, double number4, double number5) {
	double min = 2147483647;
	if (number1 < min)
		min = number1;
	if (number2 < min)
		min = number2;
	if (number3 < min)
		min = number3;
	if (number4 < min)
		min = number4;
	if (number5 < min)
		min = number5;
	return min;
}

/****************************************************************
	* Function: print_double()                                  *
	* Date Created: 9/21/2020                                   *
	* Date Last Modified: 9/21/2020                             *
	* Description: Prints a double precision number (to the     *
	*              hundredths place) to an output file.         *
	* Input parameters: Outfile and decimal number              *
	* Returns: Nothing                                          *
	* Preconditions: outfile must be open programatically       *
	* Postconditions: Nothing                                   *
	*************************************************************/
void print_double(FILE* outfile, double number) {
	fprintf(outfile, "%.2f\n", number);
}