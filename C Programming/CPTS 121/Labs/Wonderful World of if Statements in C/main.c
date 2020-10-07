#include "Parent.h"

int main() {
	FILE* infile = fopen("Input.dat", "r");
	double BMR = 0;

	double age = 0;
	fscanf(infile, "%lf", &age);

	char gender = '\0';
	fscanf(infile, "%c", &gender);
	fscanf(infile, "%c", &gender);
	
	double weight = 0;
	fscanf(infile, "%lf", &weight);

	double heightInches = 0;
	fscanf(infile, "%lf", &heightInches);

	int activity = 0;
	fscanf(infile, "%d", &activity);

	if (gender == 'M')
		BMR = 66 + (6.23 * weight) + (12.7 * heightInches) - (6.8 * age);
	else if (gender == 'F')
		BMR = 655 + (4.35 * weight) + (4.7 * heightInches) - (4.7 * age);

	if (activity == 1)
		printf("1. You need %lf calories.", BMR * 1.2);
	else if (activity == 2)
		printf("1. You need %lf calories.", BMR * 1.375);
	else if (activity == 3)
		printf("1. You need %lf calories.", BMR * 1.55);
	else if (activity == 4)
		printf("1. You need %lf calories.", BMR * 1.725);
	else if (activity == 5)
		printf("1. You need %lf calories.", BMR * 1.9);

	fclose(infile);

	char response = '\0';
	int bonus = 0;
	printf("\n\n2. All-Star Game appearance? (y/n)\n");
	scanf(" %c", &response);
	if (response == 'y')
		bonus += 25000;

	printf("Regular season MVP? (y/n)\n");
	scanf(" %c", &response);
	if (response == 'y')
		bonus += 75000;

	printf("World Series MVP? (y/n)\n");
	scanf(" %c", &response);
	if (response == 'y')
		bonus += 100000;

	printf("Gold Glove award? (y/n)\n");
	scanf(" %c", &response);
	if (response == 'y')
		bonus += 50000;

	printf("Silver Slugger award? (y/n)\n");
	scanf(" %c", &response);
	if (response == 'y')
		bonus += 35000;

	printf("Home run champ? (y/n)\n");
	scanf(" %c", &response);
	if (response == 'y')
		bonus += 25000;

	printf("Batting average champ? (y/n)\n");
	scanf(" %c", &response);
	if (response == 'y')
		bonus += 25000;

	printf("Your bonus is %d.\n", bonus);

	FILE* in = fopen("Numbers.dat", "r");
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0;
	fscanf(in, "%d", &num1);
	fscanf(in, "%d", &num2);
	fscanf(in, "%d", &num3);
	fscanf(in, "%d", &num4);
	fscanf(in, "%d", &num5);

	time_t t;
	srand((unsigned)time(&t));
	int option = (rand() % 3) + 1;

	printf("\n3.\n\t1. Average\n\t2. High Value\n\t3. Low Value\nOption %d was picked.\n", option);
	if (option == 1) 
		printf("Average of %d, %d, %d, %d, %d is %lf.\n", num1, num2, num3, num4, num5, (double)(num1 + num2 + num3 + num4 + num5) / 5.0);

	else if (option == 2) {
		int max = 0;
		if (num1 > max)
			max = num1;
		if (num2 > max)
			max = num2;
		if (num3 > max)
			max = num3;
		if (num4 > max)
			max = num4;
		if (num5 > max)
			max = num5;
		printf("Highest number of %d, %d, %d, %d, %d is %d.\n", num1, num2, num3, num4, num5, max);
	}
	else if (option == 3) {
		int min = 2147483647;
		if (num1 < min)
			min = num1;
		if (num2 < min)
			min = num2;
		if (num3 < min)
			min = num3;
		if (num4 < min)
			min = num4;
		if (num5 < min)
			min = num5;
		printf("Lowest number of %d, %d, %d, %d, %d is %d.\n", num1, num2, num3, num4, num5, min);
	}
	fclose(in);
	return 0;
}