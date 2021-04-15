/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 1 - Analyzing Fitbit Data                  *
* Date: 1/24/2021                                                       *
* Description: This program analyzes fitbit data.                       *
************************************************************************/

#include "parent.h"

/****************************************************************
	* Function: initData()                                      *
	* Date Created: 1/24/2021                                   *
	* Date Last Modified: 1/24/2021                             *
	* Description: Initializes the FitbitData array.            *
	* Input parameters: FitbitData array & infile as type FILE. *
	* Returns: Nothing                                          *
	* Preconditions: FitbitData array & infile as type FILE.    *
	* Postconditions: FitbitData array has been initialized.    *
	*************************************************************/
void initData(FitbitData* arr, FILE* infile) {
	char line[65], dup[65], check[6], check2[8], element[15], temp3[3][5];
	double temp1 = 0;
	int temp2 = 0, index = 0, probability = 0;

	//Ignores first two lines
	fgets(line, 65, infile);
	fgets(line, 65, infile);

	for (int i = 0; i < 1440; i++) {
		index = 0; //Tracker for double commas
		fgets(line, 65, infile); //Reads in a full line
		strcpy(dup, line); //strtok does wierd things with the src, so better to have a duplicate of the line variable
		strncpy(check, line, 5); //Checks patient name
		check[5] = '\0';
		strncpy(check2, line + 6, 8); //Checks for duplicate minutes
		check2[7] = '\0';

		//Line processing happens if patient name is correct and time isn't duplicated
		if ((strcmp(check, "12cx7") == 0 && i > 0 && strcmp(arr[i - 1].minute, check2) != 0) || (strcmp(check, "12cx7") == 0 && i == 0)) {
			//Records patient name into data array
			strcpy(arr[i].patient, strtok(line, ","));
			index += strlen(arr[i].patient) + 1;

			//Records time of day
			strcpy(arr[i].minute, strtok(NULL, ","));
			index += strlen(arr[i].minute) + 1;

			//Records calories at that minute
			strcpy(element, strtok(NULL, ","));
			index += strlen(element) + 1;
			temp1 = strtod(element, NULL);
			arr[i].calories = temp1;

			//Records distance
			strcpy(element, strtok(NULL, ","));
			index += strlen(element) + 1;
			temp1 = strtod(element, NULL);
			arr[i].distance = temp1;

			//Records number of floors
			strcpy(element, strtok(NULL, ","));
			index += strlen(element) + 1;
			temp2 = strtol(element, NULL, 10);
			arr[i].floors = temp2;

			//Heartrate
			strncpy(element, dup + index, 1);
			if (strcmp(element, ",") != 0) { //If data isn't missing
				strcpy(element, strtok(NULL, ","));
				temp2 = strtol(element, NULL, 10);
				arr[i].heartRate = temp2;
			}
			else { //Else a random heartrate is given which is consistent to previous data
				if(arr[i - 1].heartRate >= 60)
					arr[i].heartRate = rand() % 10 + 60;
				else if (arr[i - 1].heartRate >= 70)
					arr[i].heartRate = rand() % 10 + 70;
				else 
					arr[i].heartRate = rand() % 10 + 90;
			}

			//Records number of steps
			strcpy(element, strtok(NULL, ","));
			temp2 = strtol(element, NULL, 10);
			arr[i].steps = temp2;

			//Sleep level
			if (dup[strlen(dup) - 2] != ',') { //If data isn't missing
				strcpy(element, strtok(NULL, "\n"));
				temp2 = strtol(element, NULL, 10);
				switch (temp2) {
				case 0:
					arr[i].sleepLevel = NONE;
					break;
				case 1:
					arr[i].sleepLevel = ASLEEP;
					break;
				case 2:
					arr[i].sleepLevel = AWAKE;
					break;
				case 3:
					arr[i].sleepLevel = REALLYAWAKE;
					break;
				}
			}
			else { //Else a random sleep level other than 1 is given
				probability = rand() % 10 + 1;
				if(probability <= 5)
					arr[i].sleepLevel = AWAKE;
				else if (probability <= 9)
					arr[i].sleepLevel = REALLYAWAKE;
				else
					arr[i].sleepLevel = NONE;
			}
		}
		else
			i--; //Skips the invalid line without advancing the data array
	}
}