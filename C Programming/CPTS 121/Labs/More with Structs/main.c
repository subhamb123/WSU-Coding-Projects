#include "parent.h"

int main() {
	double total = 0, average = 0, max = 0, min = 108446744073699999995535343453453453576984765867877986576947698679457698567497567498567967947456749867985678567958679856794876598769867948589667946798734573948579874598437987598537498759879457948579573985749857948739785794857945793487598479387498574573957498579857983759873498553545353543553454353434534545459.0;
	char temp[50] = "", garbage = '\0';
	int i = 0;
	FILE* infile = fopen("payroll.txt", "r"), * outfile = fopen("paid.txt", "w");
	Employee payroll[200];
	init_employee(&payroll);

	for (; !feof(infile); i++) {
		fscanf(infile, "%s", &temp);
		strcat(payroll[i].name, temp);
		fscanf(infile, "%s", &temp);
		strcat(payroll[i].name, " ");
		strcat(payroll[i].name, temp);

		fscanf(infile, "%c", &garbage);
		fscanf(infile, "%c", &payroll[i].title);

		fscanf(infile, "%c", &garbage);
		fscanf(infile, "%lf", &payroll[i].hours_worked);

		fscanf(infile, "%c", &garbage);
		fscanf(infile, "%lf", &payroll[i].payrate);

		if (payroll[i].title == 'B') {
			double overtime = payroll[i].hours_worked - 80;
			payroll[i].payment = ((payroll[i].hours_worked - overtime) * payroll[i].payrate) + (1.5 * payroll[i].payrate * overtime);
		}
		else {
			double overtime = payroll[i].hours_worked - 80;
			payroll[i].payment = ((payroll[i].hours_worked - overtime) * payroll[i].payrate) + (1.8 * payroll[i].payrate * overtime);
		}

		total += payroll[i].payment;
		if (payroll[i].payment < min)
			min = payroll[i].payment;
		if (payroll[i].payment > max)
			max = payroll[i].payment;
	}

	average = total / i;
	fprintf(outfile, "Total: $%.2f\n", total);
	fprintf(outfile, "Average: $%.2f\n", average);
	fprintf(outfile, "Max: $%.2f\n", max);
	fprintf(outfile, "Min: $%.2f\n", min);

	fclose(infile);
	fclose(outfile);

	return 0;
}