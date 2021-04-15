/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 4 - Basic Fitness Application in C++       *
* Date: 2/26/2021                                                       *
* Description: This program is a basic fitness application.             *
************************************************************************/

#include "header.h"
#include "DietPlan.h"

/****************************************************************
* Class Function: DietPlan()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: A constructor that is called if no values are    *
*              passed on object instantiation.                  *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been initialized                *
*****************************************************************/
DietPlan::DietPlan() {
	//These are the class variables being initialized
	calorieGoal = 0;
	name = "";
	date = "";
}

/****************************************************************
* Class Function: DietPlan()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: A constructor that is called if values are passed*
*              on object instantiation.                         *
* Input parameters: int, string, string                         *
* Returns: Nothing                                              *
* Preconditions: int, string, string                            * 
* Postconditions: An object has been initialized                *
*****************************************************************/
DietPlan::DietPlan(int calorieGoal, string name, string date) {
	//"this" is used to tell the compiler which is the class variable and which is the parameter
	this->calorieGoal = calorieGoal;
	this->name = name;
	this->date = date;
}

/****************************************************************
* Class Function: DietPlan()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: A copy constructor that is called when an object *
*              is passed by value to a function                 *
* Input parameters: DietPlan&                                   *
* Returns: Nothing                                              *
* Preconditions: DietPlan&                                      *
* Postconditions: A proper copy of an object has been made      *
*****************************************************************/
DietPlan::DietPlan(DietPlan& copy) {
	//Getters are used because this function doesn't have direct access to the variables in object "copy"
	calorieGoal = copy.getCalorieGoal();
	name = copy.getName();
	date = copy.getDate();
}

/****************************************************************
* Class Function: ~DietPlan()                                   *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Destructor that doesn't do anything              *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
DietPlan::~DietPlan() {
	//Nothing here because I didn't allocate anything to the heap
}

/****************************************************************
* Class Function: getCalorieGoal()                              *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns calorie goal                             *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Calorie goal has been returned                *
*****************************************************************/
int DietPlan::getCalorieGoal() const {
	return calorieGoal;
}

/****************************************************************
* Class Function: getName()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns plan name                                *
* Input parameters: None                                        *
* Returns: string                                               *
* Preconditions: None                                           *
* Postconditions: Plan name has been returned                   *
*****************************************************************/
string DietPlan::getName() const {
	return name;
}

/****************************************************************
* Class Function: getDate()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns date                                     *
* Input parameters: None                                        *
* Returns: string                                               *
* Preconditions: None                                           *
* Postconditions: Date has been returned.                       *
*****************************************************************/
string DietPlan::getDate() const {
	return date;
}

/****************************************************************
* Class Function: setCalorieGoal()                              *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets calorie goal                                *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: Calorie goal has been updated                 *
*****************************************************************/
void DietPlan::setCalorieGoal(int goal) {
	calorieGoal = goal;
}

/****************************************************************
* Class Function: setName()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets plan name                                   *
* Input parameters: string                                      *
* Returns: Nothing                                              *
* Preconditions: string                                         *
* Postconditions: Plan name has been updated                    *
*****************************************************************/
void DietPlan::setName(string name) {
	this->name = name;
}

/****************************************************************
* Class Function: setDate()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets date                                        *
* Input parameters: string                                      *
* Returns: Nothing                                              *
* Preconditions: string                                         *
* Postconditions: Date has been updated                         *
*****************************************************************/
void DietPlan::setDate(string date) {
	this->date = date;
}

/****************************************************************
* Class Function: editGoal()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Edits calorie goal                               *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: Calorie goal has been updated.                *
*****************************************************************/
void DietPlan::editGoal(int goal) {
	setCalorieGoal(goal);
}

/****************************************************************
* Function: operator<<()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Allows an object to be used instead of its       *
*              attributes.                                      *
* Input parameters: ostream& and DietPlan&                      *
* Returns: ostream&                                             *
* Preconditions: ostream& and DietPlan&                         *
* Postconditions: The attributes are now printed to the console *
*****************************************************************/
ostream& operator<< (ostream& lhs, DietPlan& rhs) {
	//The below line is returned when for example "cout << plan" is used and "plan" is an object
	lhs << rhs.getName() << endl << "Calorie Goal: " << rhs.getCalorieGoal() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

/****************************************************************
* Function: operator<<()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Allows an object to be used instead of its       *
*              attributes.                                      *
* Input parameters: fstream& and DietPlan&                      *
* Returns: fstream&                                             *
* Preconditions: fstream& and DietPlan&                         *
* Postconditions: The attributes have been printed to the file  *
*****************************************************************/
fstream& operator<< (fstream& lhs, DietPlan& rhs) {
	lhs << rhs.getName() << endl << "Calorie Goal: " << rhs.getCalorieGoal() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

/****************************************************************
* Function: operator>>()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Allows an object to be used instead of its       *
*              attributes.                                      *
* Input parameters: fstream& and DietPlan&                      *
* Returns: fstream&                                             *
* Preconditions: fstream& and DietPlan&                         *
* Postconditions: File values have been loaded into the class   *
*****************************************************************/
fstream& operator>> (fstream& lhs, DietPlan& rhs) {
	string name = "";
	string temp = "";
	int calories = 0;
	string date = "";
	string newline = "";

	getline(lhs, name);

	getline(lhs, temp, ' '); //Similar to strtok in C
	getline(lhs, temp, ' ');
	getline(lhs, temp);
	calories = stoi(temp); //Converts str to int
	

	getline(lhs, date);

	getline(lhs, newline);

	rhs.setName(name);
	rhs.setCalorieGoal(calories);
	rhs.setDate(date);

	return lhs;
}