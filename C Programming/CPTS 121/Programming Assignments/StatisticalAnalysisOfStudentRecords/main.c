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

int main() {
	FILE* infile = fopen("input.dat", "r"), * outfile = fopen("output.dat", "w"); //Infile pointer reads the premade input.dat file and outfile pointer creates and writes on the output.dat file.
	
	//This chunk reads the input.dat file and saves pieces of info into appropriate variables for calculations.

	//Student 1
	read_integer(infile); //The top line of each block reads the student ID without saving it as it isn't used in any calculation.
	double GPA1 = read_double(infile);
	int standing1 = read_integer(infile);
	double age1 = read_double(infile);

	//Student 2
	read_integer(infile);
	double GPA2 = read_double(infile);
	int standing2 = read_integer(infile);
	double age2 = read_double(infile);

	//Student 3
	read_integer(infile);
	double GPA3 = read_double(infile);
	int standing3 = read_integer(infile);
	double age3 = read_double(infile);

	//Student 4
	read_integer(infile);
	double GPA4 = read_double(infile);
	int standing4 = read_integer(infile);
	double age4 = read_double(infile);

	//Student 5
	read_integer(infile);
	double GPA5 = read_double(infile);
	int standing5 = read_integer(infile);
	double age5 = read_double(infile);

	//For all calculations, they are all compressed down to one line for each calculation. Instead of saving the return value into a variable and using that as an actual argument, the return value is directly used as an actual argument.

	double GPAMean = calculate_mean(calculate_sum(GPA1, GPA2, GPA3, GPA4, GPA5), 5); //This variable calculates GPA mean and is saved because it is used for multiple calculations.
	print_double(outfile, GPAMean); //Prints GPA Mean
	print_double(outfile, calculate_mean(calculate_sum(standing1, standing2, standing3, standing4, standing5), 5)); //Prints Class Standing Mean
	print_double(outfile, calculate_mean(calculate_sum(age1, age2, age3, age4, age5), 5)); //Prints Age Mean
	
	fprintf(outfile, "\n"); //This doesn't call a user-made print function as this isn't required, but this improves readability of output.dat.

	print_double(outfile, calculate_standard_deviation(calculate_variance(calculate_deviation(GPA1, GPAMean), calculate_deviation(GPA2, GPAMean), calculate_deviation(GPA3, GPAMean), calculate_deviation(GPA4, GPAMean), calculate_deviation(GPA5, GPAMean), 5))); //Prints GPA Standard Deviation

	print_double(outfile, find_min(GPA1, GPA2, GPA3, GPA4, GPA5)); //Prints GPA Min
	print_double(outfile, find_max(GPA1, GPA2, GPA3, GPA4, GPA5)); //Prints GPA Max

	//Closes the two FILE pointers.

	fclose(infile);
	fclose(outfile);

	return 0;
}