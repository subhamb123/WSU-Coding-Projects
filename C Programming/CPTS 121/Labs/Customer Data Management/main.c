#include "parent.h"

int main() {
	FILE* infile = fopen("customers.txt", "r"), *outfile = fopen("charges.txt", "w");
	Profile customers[100];
	int i = 0;
	double total = 0, average = 0, min = 2000000000000000, max = 0;
	char fName[100] = "", garbage = '\0';

	initProfile(&customers);

	for (i; !feof(infile); i++) {
		fscanf(infile, "%s", &customers[i].name);
		fscanf(infile, "%s", &fName);
		strcat(customers[i].name, " ");
		strcat(customers[i].name, fName);

		fscanf(infile, "%c", &garbage);
		fscanf(infile, "%c", &customers[i].plan);

		fscanf(infile, "%c", &garbage);
		fscanf(infile, "%d", &customers[i].talk_minutes);

		fscanf(infile, "%c", &garbage);
		fscanf(infile, "%d", &customers[i].data_MB);

		if (customers[i].plan == 'A') {
			customers[i].charges = 60;
			if(customers[i].talk_minutes > 1000)
				customers[i].charges += (double) (customers[i].talk_minutes - 1000) * 0.5;

			if (customers[i].data_MB > 10000)
				customers[i].charges += (double) (customers[i].data_MB - 10000) * 0.25;
		}
		else if (customers[i].plan == 'B') {
			customers[i].charges = 85;
			if (customers[i].talk_minutes > 2000)
				customers[i].charges += (double) (customers[i].talk_minutes - 2000) * 0.4;

			if (customers[i].data_MB > 20000)
				customers[i].charges += (double) (customers[i].data_MB - 20000) * 0.15;
		}

		total += customers[i].charges;
		if (customers[i].charges > max)
			max = customers[i].charges;
		else if (customers[i].charges < min)
			min = customers[i].charges;
	}

	average = total / (double) i;

	fprintf(outfile, "Total: $%.2f\n", total);
	fprintf(outfile, "Average: $%.2f\n", average);
	fprintf(outfile, "Max: $%.2f\n", max);
	fprintf(outfile, "Min: $%.2f\n", min);

	Profile temp = {"", '\0', 0, 0, 0};

	for (int passes = 1; passes < i; passes++) {
		for (int j = 0; j < i - passes; j++) {
			if (strcmp(customers[j].name, customers[j + 1].name) < 0) {
				temp = customers[j];
				customers[j] = customers[j + 1];
				customers[j + 1] = temp;
			}
		}
	}
	
	puts("See charges.txt for statistics. Below are the names sorted Z-A.");
	for (int j = 0; j < i; j++) 
		printf("%s - Charge: $%.2f\n", customers[j].name, customers[j].charges);

	fclose(infile);
	fclose(outfile);

	return 0;
}