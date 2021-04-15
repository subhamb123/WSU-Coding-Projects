/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 7 - Attendance Tracker w/ class Templates  *
* Date: 3/30/2021                                                       *
* Description: This program manages attendance for a course.            *
************************************************************************/

#include "menu.hpp"

/****************************************************************
* Class Function: menu()                                        *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Constructor that does nothing                    *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been created                    *
*****************************************************************/
menu::menu() {
	//Does nothing
}

/****************************************************************
* Class Function: ~menu()                                       *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Destructor that does nothing                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
menu::~menu() {
	//Does nothing
}

/****************************************************************
* Class Function: runApp()                                      *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Runs the program                                 *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The program has been executed                 *
*****************************************************************/
void menu::runApp() {
	LinkedList<Data> list;
	int num = 0;

	while (num != 7) {
		cout << "Choose from the menu below" << endl << "1. Import course list" << endl << "2. Load master list" << endl << "3. Store master list" << endl << "4. Mark absences" << endl << "5. Edit absences" << endl << "6. Generate report" << endl << "7. Exit" << endl << endl;
		cin >> num;
		switch (num) {
		case 1: //If user selects import course list
			cout << "Success: " << importList<Data>(&list) << endl << endl;
			break;
		case 2: //If user selects load master list
			cout << "Success: " << loadList<Data>(&list) << endl << endl;
			break;
		case 3: //If user selects store master list
			cout << "Success: " << storeList<Data>(&list) << endl << endl;
			break;
		case 4: //If user selects mark absences
			cout << "Success: " << markAbsences<Data>(&list) << endl << endl;
			break;
		case 5: //If user selects edit absences
			cout << "Success: " << editAbsences<Data>(&list) << endl << endl;
			break;
		case 6: //If user selects generate report
			cout << "Success: " << report<Data>(&list) << endl << endl;
			break;
		case 7: //If user selects exit
			cout << "Goodbye!" << endl << endl;
			break;
		default:
			cout << "Invalid input!" << endl << endl;
			break;
		}
	}
}