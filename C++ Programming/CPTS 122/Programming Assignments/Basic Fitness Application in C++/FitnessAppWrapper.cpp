/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 4 - Basic Fitness Application in C++       *
* Date: 2/26/2021                                                       *
* Description: This program is a basic fitness application.             *
************************************************************************/

#include "header.h"
#include "FitnessAppWrapper.h"

/****************************************************************
* Class Function: FitnessAppWrapper()                           *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: A constructor that is called if no values are    *
*              passed on object instantiation.                  *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been initialized                *
*****************************************************************/
FitnessAppWrapper::FitnessAppWrapper() {
	//Initializes every element in the array
	for (int i = 0; i < 7; i++) {
		dietWeekly[i] = { 0, "", "" };
		exerciseWeekly[i] = { 0, "", "" };
	}
}

/****************************************************************
* Class Function: runApp()                                      *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Runs the program                                 *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The program has started                       *
*****************************************************************/
void FitnessAppWrapper::runApp() {
	int option = 0, num = 0, num2 = 0;

	while (option != 9) {
		option = this->displayMenu();
		switch (option) {
		case 1: //Load weekly diet plan from file.
			this->loadWeeklyPlan(this->dietStream, this->dietWeekly);
			cout << endl; //Formatting
			break;
		case 2: //Load weekly exercise plan from file.
			this->loadWeeklyPlan(this->exerciseStream, this->exerciseWeekly);
			cout << endl;
			break;
		case 3: //Store weekly diet plan to file.
			this->storeWeeklyPlan(this->dietStream, this->dietWeekly);
			cout << endl;
			break;
		case 4: //Store weekly exercise plan to file.
			this->storeWeeklyPlan(this->exerciseStream, this->exerciseWeekly);
			cout << endl;
			break;
		case 5: //Display weekly diet plan to screen.
			this->displayWeeklyPlan(this->dietWeekly);
			break;
		case 6: //Display weekly exercise plan to screen.
			this->displayWeeklyPlan(this->exerciseWeekly);
			break;
		case 7: //Edit daily diet plan.
			cout << "Which day do you want to edit? (0 for Monday to 6 for Sunday)" << endl;
			cin >> num;
			if (num >= 0 && num <= 6) {
				cout << "Enter new calorie goal" << endl;
				cin >> num2;
				if (num2 >= 0) {
					this->dietWeekly[num].editGoal(num2);
					cout << endl;
				}
				else
					cout << "Invalid input!" << endl << endl;
			}
			else
				cout << "Invalid input!" << endl << endl;
			break;
		case 8: //Edit daily exercise plan.
			cout << "Which day do you want to edit? (0 for Monday to 6 for Sunday)" << endl;
			cin >> num;
			if (num >= 0 && num <= 6) {
				cout << "Enter new step goal" << endl;
				cin >> num2;
				if (num2 >= 0) {
					this->exerciseWeekly[num].editGoal(num2);
					cout << endl;
				}
				else
					cout << "Invalid input!" << endl << endl;
			}
			else
				cout << "Invalid input!" << endl << endl;
			break;
		case 9: //Exit.
			this->storeWeeklyPlan(this->dietStream, this->dietWeekly);
			this->storeWeeklyPlan(this->exerciseStream, this->exerciseWeekly);
			cout << endl << "Goodbye!" << endl << endl;
			break;
		default:
			cout << endl << "Invalid input!" << endl << endl;
			break;
		}
	}
}

/****************************************************************
* Class Function: loadDailyPlan()                               *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Loads values from file to class                  *
* Input parameters: fstream& and DietPlan&                      *
* Returns: Nothing                                              *
* Preconditions: fstream& and DietPlan&                         *
* Postconditions: A day has been initialized w/ values from file*
*****************************************************************/
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan) {
	fileStream >> plan; //Uses overloaded operator to really set what this means.
}

/****************************************************************
* Class Function: loadWeeklyPlan()                              *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Initializes each day from file                   *
* Input parameters: fstream& and DietPlan []                    *
* Returns: Nothing                                              *
* Preconditions: fstream& and DietPlan []                       *
* Postconditions: A week is now initialized w/ values from file *
*****************************************************************/
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]) {
	fileStream.open("dietPlans.txt", ios::in);
	for (int i = 0; i < 7; i++) 
		loadDailyPlan(fileStream, weeklyPlan[i]);
	
	fileStream.close();
}

/****************************************************************
* Class Function: loadDailyPlan()                               *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Loads values from file to class                  *
* Input parameters: fstream& and ExercisePlan&                  *
* Returns: Nothing                                              *
* Preconditions: fstream& and ExercisePlan&                     *
* Postconditions: A day has been initialized w/ values from file*
*****************************************************************/
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

/****************************************************************
* Class Function: loadWeeklyPlan()                              *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Initializes each day from file                   *
* Input parameters: fstream& and ExercisePlan []                *
* Returns: Nothing                                              *
* Preconditions: fstream& and ExercisePlan []                   *
* Postconditions: A week is now initialized w/ values from file *
*****************************************************************/
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]) {
	fileStream.open("exercisePlans.txt", ios::in);
	for (int i = 0; i < 7; i++) 
		loadDailyPlan(fileStream, weeklyPlan[i]);
	
	fileStream.close();
}

/****************************************************************
* Class Function: displayDailyPlan()                            *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Displays values from class to console            *
* Input parameters: DietPlan&                                   *
* Returns: Nothing                                              *
* Preconditions: DietPlan&                                      *
* Postconditions: A day has been displayed to the console       *
*****************************************************************/
void FitnessAppWrapper::displayDailyPlan(DietPlan& plan) {
	cout << plan;
}

/****************************************************************
* Class Function: displayWeeklyPlan()                           *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Displays each day to console                     *
* Input parameters: DietPlan []                                 *
* Returns: Nothing                                              *
* Preconditions: DietPlan []                                    *
* Postconditions: A week has been displayed to the console      *
*****************************************************************/
void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) 
		displayDailyPlan(weeklyPlan[i]);
}

/****************************************************************
* Class Function: displayDailyPlan()                            *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Displays values from class to console            *
* Input parameters: ExercisePlan&                               *
* Returns: Nothing                                              *
* Preconditions: ExercisePlan&                                  *
* Postconditions: A day has been displayed to the console       *
*****************************************************************/
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan) {
	cout << plan;
}

/****************************************************************
* Class Function: displayWeeklyPlan()                           *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Displays each day to console                     *
* Input parameters: ExercisePlan []                             *
* Returns: Nothing                                              *
* Preconditions: ExercisePlan []                                *
* Postconditions: A week has been displayed to the console      *
*****************************************************************/
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++)
		displayDailyPlan(weeklyPlan[i]);
}

/****************************************************************
* Class Function: storeDailyPlan()                              *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Stores values from class to file                 *
* Input parameters: fstream& and DietPlan&                      *
* Returns: Nothing                                              *
* Preconditions: fstream& and DietPlan&                         *
* Postconditions: A day has been stored with values from class  *
*****************************************************************/
void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, DietPlan& plan) {
	fileStream << plan;
}

/****************************************************************
* Class Function: storeWeeklyPlan()                             *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Stores each day to file                          *
* Input parameters: fstream& and DietPlan []                    *
* Returns: Nothing                                              *
* Preconditions: fstream& and DietPlan []                       *
* Postconditions: A week has been stored with values from class *
*****************************************************************/
void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]) {
	fileStream.open("dietPlans.txt", ios::out);
	for (int i = 0; i < 7; i++)
		storeDailyPlan(fileStream, weeklyPlan[i]);
	fileStream.close();
}

/****************************************************************
* Class Function: storeDailyPlan()                              *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Stores values from class to file                 *
* Input parameters: fstream& and ExercisePlan&                  *
* Returns: Nothing                                              *
* Preconditions: fstream& and ExercisePlan&                     *
* Postconditions: A day has been stored with values from class  *
*****************************************************************/
void FitnessAppWrapper::storeDailyPlan(fstream& fileStream, ExercisePlan& plan) {
	fileStream << plan;
}

/****************************************************************
* Class Function: storeWeeklyPlan()                             *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Stores each day to file                          *
* Input parameters: fstream& and ExercisePlan []                *
* Returns: Nothing                                              *
* Preconditions: fstream& and ExercisePlan []                   *
* Postconditions: A week has been stored with values from class *
*****************************************************************/
void FitnessAppWrapper::storeWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]) {
	fileStream.open("exercisePlans.txt", ios::out);
	for (int i = 0; i < 7; i++)
		storeDailyPlan(fileStream, weeklyPlan[i]);
	fileStream.close();
}

/****************************************************************
* Class Function: displayMenu()                                 *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Displays the menu                                *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: The menu has been displayed                   *
*****************************************************************/
int FitnessAppWrapper::displayMenu() {
	int option = 0;

	cout << "Choose from the following menu:" << endl << endl;
	cout << "1. Load weekly diet plan from file." << endl;
	cout << "2. Load weekly exercise plan from file." << endl;
	cout << "3. Store weekly diet plan to file." << endl;
	cout << "4. Store weekly exercise plan to file." << endl;
	cout << "5. Display weekly diet plan to screen." << endl;
	cout << "6. Display weekly exercise plan to screen." << endl;
	cout << "7. Edit daily diet plan." << endl;
	cout << "8. Edit daily exercise plan." << endl;
	cout << "9. Exit" << endl << endl;
	cin >> option;

	return option;
}