/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 1 - Analyzing Fitbit Data                  *
* Date: 1/24/2021                                                       *
* Description: This program analyzes fitbit data.                       *
************************************************************************/

#include "parent.h"

int main() {
	srand((unsigned int)time(NULL)); //Initializes random
	FILE* infile = fopen("FitbitData.csv", "r"), * outfile = fopen("Results.csv", "w"); //Opens files
	if (infile != NULL && outfile != NULL) //Checks if files were opened successfully
		puts("Files opened successfully!\n----------");

	FitbitData arr[1440];
	double calories = 0, distance = 0, heartRate = 0;
	int floors = 0, steps = 0, maxSteps = 0, add = 0, poorSleep = 0, temp = 1, temp2 = 0;
	char min[10] = "", max[10] = "", minTemp[10] = "", maxTemp[10] = "";

	initData(&arr, infile); //Initializes FitbitData array

	//This block calculates the summary of the data
	for (int i = 0; i < 1440; i++) {
		//Accumulation of a datapoint
		calories += arr[i].calories;
		distance += arr[i].distance;
		floors += arr[i].floors;
		steps += arr[i].steps;
		heartRate += arr[i].heartRate;
		
		if (arr[i].steps > maxSteps) //Determines the max steps at a particular minute
			maxSteps = arr[i].steps;

		if (arr[i].sleepLevel > 1) {
			if (temp) { //Determines start of interval
				strcpy(minTemp, arr[i].minute);
				temp = 0;
			}
			add += arr[i].sleepLevel;
		}
		else if (temp == 0) {
			strcpy(maxTemp, arr[i - 1].minute); //End of interval
			temp = 1; //Start of interval is now available
			temp2 = add;
			add = 0;
		}

		if (temp2 > poorSleep && temp) { //Checks if the current total is higher than the previous total and if end of interval is recorded.
			poorSleep = temp2;
			temp2 = 0;
			strcpy(min, minTemp); //Start of interval
			strcpy(max, maxTemp); //End of interval
		}
	}

	heartRate /= 1440; //Average heart rate

	//Summary and log printed to outfile and screen
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Greatest Poor Sleep Interval\n");
	fprintf(outfile, "%lf,%lf,%d,%d,%lf,%d,%s-%s\n", calories, distance, floors, steps, heartRate, maxSteps, min, max);
	for (int i = 0; i < 1440; i++) 
		fprintf(outfile, "%s,%s,%lf,%lf,%d,%d,%d,%d\n", arr[i].patient, arr[i].minute, arr[i].calories, arr[i].distance, arr[i].floors, arr[i].heartRate, arr[i].steps, arr[i].sleepLevel);

	printf("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Greatest Poor Sleep Interval\n");
	printf("%lf,%lf,%d,%d,%lf,%d,%s-%s\n", calories, distance, floors, steps, heartRate, maxSteps, min, max);
	for (int i = 0; i < 1440; i++)
		printf("%s,%s,%lf,%lf,%d,%d,%d,%d\n", arr[i].patient, arr[i].minute, arr[i].calories, arr[i].distance, arr[i].floors, arr[i].heartRate, arr[i].steps, arr[i].sleepLevel);

	puts("----------\nLog in Results.csv as well!");

	fclose(infile);
	fclose(outfile);
	return 0;
}