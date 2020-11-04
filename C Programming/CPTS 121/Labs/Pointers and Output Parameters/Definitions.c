#include "Parent.h"

void charges(double* charge, double* average, FILE* infile) {
	double hours = 0;
	fscanf(infile, "%lf", &hours);
	fscanf(infile, "%lf", &hours);
	fscanf(infile, "%lf", &hours);
	fscanf(infile, "%lf", &hours);
	double duplicate = hours;

	if (hours <= 10)
		*charge = 7.99;
	else {
		hours -= 10;
		*charge = 7.99 + 1.99 * hours;
	}

	*average = *charge / duplicate;
}

double round_money(double charge) {
	charge *= 100;
	charge = (charge > (floor(charge) + 0.5)) ? ceil(charge) : floor(charge);
	return charge /= 100;
}

void revenue(double* R, int t) {
	*R = 203.265 * pow(1.071, t);
}

void predict(int* year, double revenue) {
	if (revenue <= 203.265)
		*year = 1984;
	else {
		*year = log10(revenue / 203.265) / log10(1.071) + 1984;
	}
}