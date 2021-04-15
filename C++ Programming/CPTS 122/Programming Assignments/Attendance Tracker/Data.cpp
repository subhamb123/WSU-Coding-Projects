/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 7 - Attendance Tracker w/ class Templates  *
* Date: 3/30/2021                                                       *
* Description: This program manages attendance for a course.            *
************************************************************************/

#include "Data.hpp"

/****************************************************************
* Class Function: Stack()                                       *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Constructor that initializes the variables       *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been created                    *
*****************************************************************/
Stack::Stack() {
	mSize = 0;
	mTop = new string[365];
}

/****************************************************************
* Class Function: ~Stack()                                      *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Destructor that deletes array from heap          *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
Stack::~Stack() {
	delete[] mTop;
}

/****************************************************************
* Class Function: operator=()                                   *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Operator overloading to remove "=" ambiguity     *
* Input parameters: Stack&                                      *
* Returns: Stack&                                               *
* Preconditions: Stack&                                         *
* Postconditions: An object has been copied                     *
*****************************************************************/
Stack& Stack::operator= (const Stack& rhs) {
	string* temp = rhs.getArray();
	if (this != &rhs) {
		mSize = rhs.getSize();
		mTop = new string[365];
		for (int i = 0; i < mSize; i++)
			mTop[i] = temp[i];
	}

	return *this;
}

/****************************************************************
* Class Function: getSize()                                     *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Returns array size                               *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Array size has been returned                  *
*****************************************************************/
int Stack::getSize() const {
	return mSize;
}

/****************************************************************
* Class Function: getArray()                                    *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Returns array                                    *
* Input parameters: None                                        *
* Returns: string*                                              *
* Preconditions: None                                           *
* Postconditions: Array has been returned                       *
*****************************************************************/
string* Stack::getArray() const {
	return mTop;
}

/****************************************************************
* Class Function: push()                                        *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Date is pushed to the top of the stack           *
* Input parameters: string                                      *
* Returns: Nothing                                              *
* Preconditions: string                                         *
* Postconditions: Date has been added                           *
*****************************************************************/
void Stack::push(string newItem) {
	mTop[mSize] = newItem;
	mSize++;
}

/****************************************************************
* Class Function: pop()                                         *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Date is removed from the stack                   *
* Input parameters: string&                                     *
* Returns: Nothing                                              *
* Preconditions: string&                                        *
* Postconditions: Date has been removed                         *
*****************************************************************/
void Stack::pop(string& poppedItem) {
	if (!isEmpty()) {
		poppedItem = mTop[mSize - 1];
		mTop[mSize - 1] = "";
		mSize--;
	}
}

/****************************************************************
* Class Function: peek()                                        *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Shows what is at the top of the array            *
* Input parameters: string&                                     *
* Returns: Nothing                                              *
* Preconditions: string&                                        *
* Postconditions: An object has been created                    *
*****************************************************************/
void Stack::peek(string& item) {
	if (!isEmpty())
		item = mTop[mSize - 1];
}

/****************************************************************
* Class Function: isEmpty()                                     *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Checks if array is empty                         *
* Input parameters: None                                        *
* Returns: bool                                                 *
* Preconditions: None                                           *
* Postconditions: Conditional has been returned                 *
*****************************************************************/
bool Stack::isEmpty() {
	return mSize == 0;
}

/****************************************************************
* Class Function: Data()                                        *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Constructor that initializes the variables       *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been created                    *
*****************************************************************/
Data::Data() {
	recNum = 0;
	ID = 0;
	name = "";
	email = "";
	units = "";
	major = "";
	level = "";
	absences = 0;
}

/****************************************************************
* Class Function: ~Data()                                       *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Destructor that does nothing                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
Data::~Data() {
	//What data to delete is managed when the list is deleted.
}

/****************************************************************
* Class Functions: setters                                      *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Sets the values of the private data members      *
* Input parameters: int/string/Stack&                           *
* Returns: Nothing                                              *
* Preconditions: int/string/Stack&                              *
* Postconditions: A data member has been set.                   *
*****************************************************************/

void Data::setRecNum(int n) {
	recNum = n;
}

void Data::setID(int n) {
	ID = n;
}

void Data::setName(string s) {
	name = s;
}

void Data::setEmail(string s) {
	email = s;
}

void Data::setUnits(string s) {
	units = s;
}

void Data::setMajor(string s) {
	major = s;
}

void Data::setLevel(string s) {
	level = s;
}

void Data::setAbsences(int n) {
	absences = n;
}

void Data::setAbsenceDates(Stack& s) {
	absenceDates = s;
}

/****************************************************************
* Class Function: incrementAbsences()                           *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Increments the absences                          *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: Absences has been incremented                 *
*****************************************************************/
void Data::incrementAbsences() {
	absences++;
}

/****************************************************************
* Class Function: decrementAbsences()                           *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Decrements the absences                          *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: Absences has been decremented                 *
*****************************************************************/
void Data::decrementAbsences() {
	absences--;
}

/****************************************************************
* Class Functions: getters                                      *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Gets the values of the private data members      *
* Input parameters: None                                        *
* Returns: int/string/Stack&                                    *
* Preconditions: None                                           *
* Postconditions: A data member has been returned.              *
*****************************************************************/

int Data::getRecNum() const {
	return recNum;
}

int Data::getID() const {
	return ID;
}

string Data::getName() const {
	return name;
}

string Data::getEmail() const {
	return email;
}

string Data::getUnits() const {
	return units;
}

string Data::getMajor() const {
	return major;
}

string Data::getLevel() const {
	return level;
}

int Data::getAbsences() const {
	return absences;
}

Stack& Data::getAbsenceDates() {
	return absenceDates;
}