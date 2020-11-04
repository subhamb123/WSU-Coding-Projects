#include "Parent.h"

int main() {
	FILE* infile = fopen("input.dat", "r"), * outfile = fopen("output.dat", "w");
	double charge = 0, average = 0;

	charges(&charge, &average, infile);
	fprintf(outfile, "Charge: $%lf, Average cost per hour: $%lf", round_money(charge), round_money(average));
	printf("1. Look at output.dat.\n");
	fclose(infile);
	fclose(outfile);

	double R = 0;
	int year = 0, i = 0;
	outfile = fopen("table.dat", "w");
	printf("2. Look at table.dat.\n");

	do {
		revenue(&R, i);
		predict(&year, R);
		fprintf(outfile, "%d: $%.2f\n", year, R * 1000000);
		i++;
	} while (R <= 1000000);
	
	return 0;
}