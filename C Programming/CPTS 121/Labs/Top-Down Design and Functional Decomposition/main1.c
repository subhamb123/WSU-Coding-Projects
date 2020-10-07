//Uncomment this file to compile 1st problem

/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double get_weight();
double get_height();
double convert_feet_to_inches(double height_in_feet);
double calculate_bmi(double weight_in_pounds, double height_in_feet);
void display_bmi(double bmi);

int main() {
	double weight = get_weight();
	double height = get_height();
	double inches = convert_feet_to_inches(height);
	double bmi = calculate_bmi(weight, inches);
	display_bmi(bmi);
	return 0;
}

double get_weight() {
	double weight = 0;
	printf("Enter weight in pounds: ");
	scanf("%lf", &weight);
	return weight;
}
double get_height() {
	double height = 0;
	printf("Enter height in feet: ");
	scanf("%lf", &height);
	return height;
}
double convert_feet_to_inches(double height_in_feet) {
	return height_in_feet * (double) 12;
}
double calculate_bmi(double weight_in_pounds, double height_in_inches) {
	return ((weight_in_pounds) / pow(height_in_inches, 2)) * (double) 703;
}
void display_bmi(double bmi) {
	printf("BMI: %.1f\n", bmi);
}*/