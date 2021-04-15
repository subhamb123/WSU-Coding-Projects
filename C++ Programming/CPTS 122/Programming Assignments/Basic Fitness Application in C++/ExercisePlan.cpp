/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 4 - Basic Fitness Application in C++       *
* Date: 2/26/2021                                                       *
* Description: This program is a basic fitness application.             *
************************************************************************/

#include "header.h"
#include "ExercisePlan.h"

/****************************************************************
* Class Function: ExercisePlan()                                *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: A constructor that is called if no values are    *
*              passed on object instantiation.                  *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been initialized                *
*****************************************************************/
ExercisePlan::ExercisePlan() {
	stepGoal = 0;
	planName = "";
	date = "";
}

/****************************************************************
* Class Function: ExercisePlan()                                *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: A constructor that is called if values are passed*
*              on object instantiation.                         *
* Input parameters: int, string, string                         *
* Returns: Nothing                                              *
* Preconditions: int, string, string                            *
* Postconditions: An object has been initialized                *
*****************************************************************/
ExercisePlan::ExercisePlan(int stepGoal, string name, string date) {
	this->stepGoal = stepGoal;
	this->planName = name;
	this->date = date;
}

/****************************************************************
* Class Function: ExercisePlan()                                *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: A copy constructor that is called when an object *
*              is passed by value to a function                 *
* Input parameters: ExercisePlan&                               *
* Returns: Nothing                                              *
* Preconditions: ExercisePlan&                                  *
* Postconditions: A proper copy of an object has been made      *
*****************************************************************/
ExercisePlan::ExercisePlan(ExercisePlan& copy) {
	stepGoal = copy.getStepGoal();
	planName = copy.getName();
	date = copy.getDate();
}

/****************************************************************
* Class Function: ~ExercisePlan()                               *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Destructor that doesn't do anything              *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
ExercisePlan::~ExercisePlan() {

}

/****************************************************************
* Class Function: getStepGoal()                                 *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns step goal                                *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Step goal has been returned                   *
*****************************************************************/
int ExercisePlan::getStepGoal() const {
	return stepGoal;
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
string ExercisePlan::getName() const {
	return planName;
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
string ExercisePlan::getDate() const {
	return date;
}

/****************************************************************
* Class Function: setStepGoal()                                 *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets step goal                                   *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: Step goal has been updated                    *
*****************************************************************/
void ExercisePlan::setStepGoal(int goal) {
	stepGoal = goal;
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
void ExercisePlan::setName(string name) {
	planName = name;
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
void ExercisePlan::setDate(string date) {
	this->date = date;
}

/****************************************************************
* Class Function: editGoal()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Edits step goal                                  *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: Step goal has been updated.                   *
*****************************************************************/
void ExercisePlan::editGoal(int goal) {
	setStepGoal(goal);
}

/****************************************************************
* Function: operator<<()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Allows an object to be used instead of its       *
*              attributes.                                      *
* Input parameters: ostream& and ExercisePlan&                  *
* Returns: ostream&                                             *
* Preconditions: ostream& and ExercisePlan&                     *
* Postconditions: The attributes are now printed to the console *
*****************************************************************/
ostream& operator<< (ostream& lhs, ExercisePlan& rhs) {
	lhs << rhs.getName() << endl << "Step Goal: " << rhs.getStepGoal() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

/****************************************************************
* Function: operator<<()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Allows an object to be used instead of its       *
*              attributes.                                      *
* Input parameters: fstream& and ExercisePlan&                  *
* Returns: fstream&                                             *
* Preconditions: fstream& and ExercisePlan&                     *
* Postconditions: The attributes have been printed to the file  *
*****************************************************************/
fstream& operator<< (fstream& lhs, ExercisePlan& rhs) {
	lhs << rhs.getName() << endl << "Step Goal: " << rhs.getStepGoal() << endl << rhs.getDate() << endl << endl;

	return lhs;
}

/****************************************************************
* Function: operator>>()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Allows an object to be used instead of its       *
*              attributes.                                      *
* Input parameters: fstream& and ExercisePlan&                  *
* Returns: fstream&                                             *
* Preconditions: fstream& and ExercisePlan&                     *
* Postconditions: File values have been loaded into the class   *
*****************************************************************/
fstream& operator>> (fstream& lhs, ExercisePlan& rhs) {
	string name = "";
	string temp = "";
	int steps = 0;
	string date = "";
	string newline = "";

	getline(lhs, name);

	getline(lhs, temp, ' ');
	getline(lhs, temp, ' ');
	getline(lhs, temp);
	steps = stoi(temp);
	
	getline(lhs, date);
	
	getline(lhs, newline);

	rhs.setName(name);
	rhs.setStepGoal(steps);
	rhs.setDate(date);

	return lhs;
}