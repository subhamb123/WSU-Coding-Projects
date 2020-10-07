#include "parent.h"

int main() {
	FILE *infile = fopen("salaries.txt", "r");
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0;

	fscanf(infile, "%d", &n1);
	fscanf(infile, "%d", &n2);
	fscanf(infile, "%d", &n3);
	fscanf(infile, "%d", &n4);

	int total = n1 + n2 + n3 + n4;
	if (total < 15000)
		printf("1. l\n");
	else if (total < 200000)
		printf("1. m\n");
	else
		printf("1. h\n");

	fclose(infile);

	infile = fopen("data.txt", "r");
	FILE * outfile = fopen("output.txt", "w");
	int count = 0;
	double sum = 0, temp = 0;

	while (!feof(infile)){
		fscanf(infile, "%lf", &temp);
		sum += temp;
		count++;
	}

	fprintf(outfile, "%lf", sum / (double)count);

	fclose(infile);
	fclose(outfile);

	printf("2. Result in output.txt.\n");

	/*infile = fopen("input.txt", "r"), outfile = fopen("GCD.txt", "w");
	int num1 = 0, num2 = 0;
	int condition = 0;

	num1 = read_data(infile);
	num2 = read_data(infile);

	while (condition != 1) {

	}*/

	infile = fopen("input.txt", "r");
	int min = 0, max = 0, temporary = 0;
	fscanf(infile, "%d", &min);

	for (; !feof(infile);) {
		fscanf(infile, "%d", &temporary);
		if (temporary > max)
			max = temporary;
		else if (temporary < min)
			min = temporary;
	}

	printf("4. Min: %d, Max: %d\n", min, max);
	fclose(infile);
	return 0;
}