#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0, slope = 0, xmid = 0, ymid = 0, slopeBisect = 0, yIntBisect = 0;
	printf("1. Enter point 1 in the format of x1 y1\n");
	scanf("%lf%lf", &x1, &y1);
	printf("Enter point 2 in the format of x2 y2\n");
	scanf("%lf%lf", &x2, &y2);
	slope = (y2 - y1) / (x2 - x1);
	xmid = (x1 + x2) / 2;
	ymid = (y1 + y2) / 2;
	slopeBisect = -(1 / slope);
	yIntBisect = ymid - (slopeBisect * xmid);
	printf("Point 1: (%lf, %lf)\nPoint 2: (%lf, %lf)\nEquation of perpendicular bisector: y = %lfx + %lf\n\n", x1, y1, x2, y2, slopeBisect, yIntBisect);

	double weight = 0, height = 0;
	printf("2. Input your weight in pounds and height in feet\n");
	scanf("%lf%lf", &weight, &height);
	height *= 12;
	printf("BMI = ((%lf) / (%lf)^2) * 703 = %lf\n\n", weight, height, ((weight) / (pow(height, 2)) * 703));

	double harris = 0, coaches = 0, computer = 0;
	printf("3. Enter Harris Poll score (any number between 1 and 2,850): ");
	scanf("%lf", &harris);
	printf("Enter Coaches Poll score (any number between 1 and 1,475): ");
	scanf("%lf", &coaches);
	printf("Enter computer ranking (any number between 0 and 1): ");
	scanf("%lf", &computer);
	harris /= 2850;
	coaches /= 1475;
	printf("BCS_score = (%lf + %lf + %lf) / 3 = %lf\n", harris, coaches, computer, (harris + coaches + computer) / 3);

	return 0;
}