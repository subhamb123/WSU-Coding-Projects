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

//Function Definitions

/****************************************************************
	* Function: calculate_series_resistance()                   *
	* Date Created: 9/11/2020                                   *
	* Date Last Modified: 9/11/2020                             *
	* Description: This function calculates series resistance in*
	*              ohms.                                        *
	* Input parameters: Resistors 1, 2, and 3                   *
	* Returns: Sum of the three resistors in ohms.              *
	* Preconditions: Resistors 1, 2, and 3                      *
	* Postconditions: The sum of the resistors has been         *
	*                 calculated in ohms.                       *
	*************************************************************/
int calculate_series_resistance(int r1, int r2, int r3) {
	return r1 + r2 + r3;
}

/****************************************************************
	* Function: calculate_total_sales_tax()                     *
	* Date Created: 9/11/2020                                   *
	* Date Last Modified: 9/11/2020                             *
	* Description: This function calculates sales tax in dollars*
	* Input parameters: Sales tax rate and item cost.           *
	* Returns: Sales tax in dollars                             *
	* Preconditions: Sales tax rate and item cost.              *
	* Postconditions: The sales tax has been calculated in      *
	*                 dollars.                                  *
	*************************************************************/
double calculate_total_sales_tax(double sales_tax_rate, double item_cost) {
	return 0.01 * sales_tax_rate * item_cost;
}

/****************************************************************
	* Function: calculate_volume_pyramid()                      *
	* Date Created: 9/11/2020                                   *
	* Date Last Modified: 9/11/2020                             *
	* Description: This function calculates volume of a pyramid.*
	* Input parameters: Length, width, and height               *
	* Returns: Volume of a pyramid                              *
	* Preconditions: Length, width, and height                  *
	* Postconditions: The volume has been calculated.           *
	*************************************************************/
double calculate_volume_pyramid(double l, double w, double h) {
	return (l * w * h) / 3;
}

/****************************************************************
	* Function: calculate_parallel_resistance()                 *
	* Date Created: 9/11/2020                                   *
	* Date Last Modified: 9/11/2020                             *
	* Description: This function calculates parallel resistance *
	*              in ohms.                                     *
	* Input parameters: Resistors 1, 2, and 3                   *
	* Returns: The parallel resistance of the three resistors in*
	*           ohms.                                           *
	* Preconditions: Resistors 1, 2, and 3                      *
	* Postconditions: The parallel resistance was calculated in *
	*                 ohms.                                     *
	*************************************************************/
double calculate_parallel_resistance(int r1, int r2, int r3) {
	return 1 / (1 / (double)r1 + 1 / (double)r2 + 1 / (double)r3); //The resistance values need to be typecasted so the decimal values get carried all throughout the calculation.
}

/****************************************************************
	* Function: character_encoding()                            *
	* Date Created: 9/11/2020                                   *
	* Date Last Modified: 9/11/2020                             *
	* Description: This function encodes a character using      *
	*              special operations.                          *
	* Input parameters: A character and an integer              *
	* Returns: ASCII value of encoded character                 *
	* Preconditions: A character and an integer                 *
	* Postconditions: The ASCII value has been calculated.      *
	*************************************************************/
int character_encoding(int plainText, int shiftInt) {
	return (plainText - (int)'a') + (int)'A' - shiftInt;
}

/****************************************************************
	* Function: distance_two_points()                           *
	* Date Created: 9/11/2020                                   *
	* Date Last Modified: 9/11/2020                             *
	* Description: This function calculates distance between two*
	*              points.                                      *
	* Input parameters: x1 and y1 for point 1 and x2 and y2 for *
	*                   point 2.                                *
	* Returns: Distance between two points                      *
	* Preconditions: x1 and y1 for point 1 and x2 and y2 for    *
	*                point 2.                                   *
	* Postconditions: The distance has been calculated.         *
	*************************************************************/
double distance_two_points(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)); //sqrt and pow only available with math header file
}

/****************************************************************
	* Function: calculate_general_equation()                    *
	* Date Created: 9/11/2020                                   *
	* Date Last Modified: 9/11/2020                             *
	* Description: This function outputs a value using input and*
	*              putting it into the equation.                *
	* Input parameters: y, z, and x as floats and a as integer  *
	* Returns: A float value                                    *
	* Preconditions: y, z, and x as floats and a as integer     *
	* Postconditions: A float value has been calculated.        *
	*************************************************************/
double calculate_general_equation(double y, double z, double x, int a) {
	return y / ((double)3 / (double)17) - z + x / (a % 2) + PI; //The PI macros is used here. It gets replaced with the number value
}