#include "duration.h"

double theta() {
	double theta = 0;
	printf("This program computes the duration of a projectile's flight and its height above the ground when it reaches the target.\nEnter angle in radians: ");
	scanf("%lf", &theta);
	return theta;
}
double distance() {
	double distance = 0;
	printf("Enter distance in feet to the target: ");
	scanf("%lf", &distance);
	return distance;
}
double velocity() {
	double velocity = 0;
	printf("Enter velocity in ft/sec: ");
	scanf("%lf", &velocity);
	return velocity;
}