/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 7 - Attendance Tracker w/ class Templates  *
* Date: 3/30/2021                                                       *
* Description: This program manages attendance for a course.            *
************************************************************************/

//Guard Code
#pragma once

//Header Files
#include "LinkedList.hpp"

/****************************************************************
* Function: importList()                                        *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Overrides the list with data from file           *
* Input parameters: LinkedList<T>*                              *
* Returns: bool                                                 *
* Preconditions: LinkedList<T>*                                 *
* Postconditions: Data has been imported                        *
*****************************************************************/
template <class T>
bool importList(LinkedList<T>* list) {
	list->deleteList(list->getHead()); //Allows overriding list
	Data data;
	string temp = "";
	int temp2 = 0;
	char temp3 = '\0';
	bool success = false;
	fstream infile;
	infile.open("classList.csv", ios::in);

	//Imports data into list
	getline(infile, temp);
	while (!infile.eof()) {
		success = true;
		infile >> temp2;
		data.setRecNum(temp2);
		infile >> temp3;

		infile >> temp2;
		data.setID(temp2);
		infile >> temp3;
		infile >> temp3;

		getline(infile, temp, '\"');
		data.setName(temp);
		infile >> temp3;

		getline(infile, temp, ',');
		data.setEmail(temp);

		getline(infile, temp, ',');
		data.setUnits(temp);

		getline(infile, temp, ',');
		data.setMajor(temp);

		getline(infile, temp);
		data.setLevel(temp);

		list->insertFront(data); 
	}

	infile.close();
	return success;
}

/****************************************************************
* Function: loadList()                                          *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Appends to the list with data from file          *
* Input parameters: LinkedList<T>*                              *
* Returns: bool                                                 *
* Preconditions: LinkedList<T>*                                 *
* Postconditions: Data has been loaded and appended             *
*****************************************************************/
template <class T>
bool loadList(LinkedList<T>* list) {
	Data data;
	Stack storeDates;
	string temp = "", temp4 = "";
	int temp2 = 0;
	char temp3 = '\0';
	bool success = false;
	fstream infile;
	infile.open("master.txt", ios::in);

	getline(infile, temp);
	while (!infile.eof()) {
		success = true;
		infile >> temp2;
		data.setRecNum(temp2);
		infile >> temp3;

		infile >> temp2;
		data.setID(temp2);
		infile >> temp3;
		infile >> temp3;

		getline(infile, temp, '\"');
		data.setName(temp);
		infile >> temp3;

		getline(infile, temp, ',');
		data.setEmail(temp);

		getline(infile, temp, ',');
		data.setUnits(temp);

		getline(infile, temp, ',');
		data.setMajor(temp);

		getline(infile, temp, ',');
		data.setLevel(temp);

		infile >> temp2;
		data.setAbsences(temp2);
		
		while (!storeDates.isEmpty())
			storeDates.pop(temp); //Clears temporary variable for next use
		getline(infile, temp);
		getline(infile, temp);
		if (temp[0] == 'A') {
			getline(infile, temp);
			for (int i = 0; i < temp.length(); i++) {
				if (temp[i] != ',')
					temp4 += temp[i];
				else {
					storeDates.push(temp4);
					temp4 = "";
					i++;
				}
			}

			storeDates.push(temp4);
			temp4 = "";
			data.setAbsenceDates(storeDates);
		}

		list->insertFront(data);
	}

	infile.close();
	return success;
}

/****************************************************************
* Function: storeList()                                         *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Stores the list to the file.                     *
* Input parameters: LinkedList<T>*                              *
* Returns: bool                                                 *
* Preconditions: LinkedList<T>*                                 *
* Postconditions: Data has been stored                          *
*****************************************************************/
template <class T>
bool storeList(LinkedList<T>* list) {
	bool success = false;
	fstream outfile;
	outfile.open("master.txt", ios::out);

	Node<T>* pCur = list->getHead(); //Variable to traverse through list

	//Outputs data to file
	outfile << "#,ID,Name,Email,Units,Program,Level,Absences" << endl << endl;
	while (pCur != nullptr) {
		success = true;
		outfile << pCur->getData().getRecNum() << ",";
		outfile << pCur->getData().getID() << ",";
		outfile << "\"" << pCur->getData().getName() << "\",";
		outfile << pCur->getData().getEmail() << ",";
		outfile << pCur->getData().getUnits() << ",";
		outfile << pCur->getData().getMajor() << ",";
		outfile << pCur->getData().getLevel() << ",";
		outfile << pCur->getData().getAbsences();
		if (pCur->getData().getAbsences() != 0) {
			outfile << endl << "Absence Dates:" << endl;
			string* temp = pCur->getData().getAbsenceDates().getArray();
			int j = 0;
			for (j; j < pCur->getData().getAbsenceDates().getSize() - 1; j++)
				outfile << temp[j] << ", ";

			//Formatting purposes
			if (pCur->getNext() != nullptr)
				outfile << temp[j] << endl << endl;
			else
				outfile << temp[j];
		}
		else if (pCur->getNext() != nullptr) 
			outfile << endl << endl;

		pCur = pCur->getNext();
	}

	outfile.close();

	return success;
}

/****************************************************************
* Function: markAbsences()                                      *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Marks which student was absent                   *
* Input parameters: LinkedList<T>*                              *
* Returns: bool                                                 *
* Preconditions: LinkedList<T>*                                 *
* Postconditions: Absences have been marked                     *
*****************************************************************/
template <class T>
bool markAbsences(LinkedList<T>* list) {
	bool success = false;
	char response = '\0';
	Node<T>* pCur = list->getHead();

	//Get time now
	time_t t = time(0);
	struct tm* now = localtime(&t);
	cout << "Date: " << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << endl;
	string date;

	while (pCur != nullptr) {
		success = true;
		cout << "Is " << pCur->getData().getName() << " absent today? (y/n): ";
		cin >> response;
		response = tolower(response);
		if (response == 'y') {
			pCur->getData().getAbsenceDates().push(to_string(now->tm_year + 1900) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_mday)); //Pushes date as string to array
			pCur->getData().incrementAbsences();
		}

		pCur = pCur->getNext();
	}

	return success;
}

/****************************************************************
* Function: editAbsences()                                      *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Deletes absences for a student                   *
* Input parameters: LinkedList<T>*                              *
* Returns: bool                                                 *
* Preconditions: LinkedList<T>*                                 *
* Postconditions: Edits have been made                          *
*****************************************************************/
template <class T>
bool editAbsences(LinkedList<T>* list) {
	bool success = false;
	int num = 0;
	char response = '\0';
	string temp = "", temp2 = "";
	Stack s; //Auxillery stack to help remove a particular date

	cout << "Choose from the menu below" << endl << "1. Search by ID" << endl << "2. Search by name" << endl << endl;
	cin >> num;

	switch (num) {
	case 1: {
		Node<T>* pCur = list->getHead();
		cout << "Enter the ID of the student" << endl;
		cin >> num;
		while (pCur != nullptr && pCur->getData().getID() != num)
			pCur = pCur->getNext();

		if (pCur != nullptr) {
			cout << "Would you like to populate the stack with random absence dates? (y/n)" << endl;
			cin >> response;
			response = tolower(response);
			if (response == 'y') {
				for (int i = 0; i < 10; i++) {
					temp = "2021-" + to_string(rand() % 12 + 1) + "-" + to_string(rand() % 30 + 1);
					pCur->getData().getAbsenceDates().push(temp);
					pCur->getData().incrementAbsences();
				}
			}

			if (pCur->getData().getAbsences() != 0) {
				cout << "Absence Dates: ";
				string* arr = pCur->getData().getAbsenceDates().getArray();
				int j = 0;
				for (j; j < pCur->getData().getAbsenceDates().getSize() - 1; j++)
					cout << arr[j] << ", ";

				cout << arr[j] << endl << endl << "Enter the date you would like to remove to mark that student present for that day." << endl;
				cin >> temp;

				for (int i = pCur->getData().getAbsenceDates().getSize() - 1; i >= 0; i--) {
					if (arr[i] != temp) {
						pCur->getData().getAbsenceDates().pop(temp2);
						s.push(temp2);
					}
					else {
						success = true;
						pCur->getData().getAbsenceDates().pop(temp2);
						pCur->getData().decrementAbsences();
						break;
					}
				}

				while (!s.isEmpty()) {
					s.pop(temp2);
					pCur->getData().getAbsenceDates().push(temp2);
				}
			}
			else
				cout << "That student doesn't have any absences" << endl;
		}
		else
			cout << "That student doesn't exist" << endl;

		break;
	}
	case 2: {
		Node<T>* pCur = list->getHead();

		cout << "Enter the name of the student (Last,First)" << endl;
		cin >> temp;

		while (pCur != nullptr && pCur->getData().getName() != temp)
			pCur = pCur->getNext();

		if (pCur != nullptr) {
			cout << "Would you like to populate the stack with random absence dates? (y/n)" << endl;
			cin >> response;
			response = tolower(response);
			if (response == 'y') {
				for (int i = 0; i < 10; i++) {
					temp = "2021-" + to_string(rand() % 12 + 1) + "-" + to_string(rand() % 30 + 1);
					pCur->getData().getAbsenceDates().push(temp);
					pCur->getData().incrementAbsences();
				}
			}

			if (pCur->getData().getAbsences() != 0) {
				cout << "Absence Dates: ";
				string* arr = pCur->getData().getAbsenceDates().getArray();
				int j = 0;
				for (j; j < pCur->getData().getAbsenceDates().getSize() - 1; j++)
					cout << arr[j] << ", ";

				cout << arr[j] << endl << endl << "Enter the date you would like to remove to mark that student present for that day." << endl;
				cin >> temp;

				for (int i = pCur->getData().getAbsenceDates().getSize() - 1; i >= 0; i--) {
					if (arr[i] != temp) {
						pCur->getData().getAbsenceDates().pop(temp2);
						s.push(temp2);
					}
					else {
						success = true;
						pCur->getData().getAbsenceDates().pop(temp2);
						pCur->getData().decrementAbsences();
						break;
					}
				}

				while (!s.isEmpty()) {
					s.pop(temp2);
					pCur->getData().getAbsenceDates().push(temp2);
				}
			}
			else
				cout << "That student doesn't have any absences" << endl;
		}
		else
			cout << "That student doesn't exist" << endl;
		break;
	}
	default:
		cout << "Invalid input!" << endl << endl;
		break;
	}

	return success;
}

/****************************************************************
* Function: report()                                            *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Generates one of two reports                     *
* Input parameters: LinkedList<T>*                              *
* Returns: bool                                                 *
* Preconditions: LinkedList<T>*                                 *
* Postconditions: A report has been generated                   *
*****************************************************************/
template <class T>
bool report(LinkedList<T>* list) {
	fstream outfile;
	bool success = false;
	int num = 0;
	cout << "Choose from the menu below" << endl << "1. Generate report for all students" << endl << "2. Generate report for students with absences that match or exceed a certain threshold" << endl << endl;
	cin >> num;
	switch (num) {
	case 1: {
		Node<T>* pCur = list->getHead();
		success = true;
		outfile.open("allStudentsReport.txt", ios::out);

		outfile << "#,Name,Absences" << endl << endl;
		while (pCur != nullptr) {
			outfile << pCur->getData().getRecNum() << ",";
			outfile << "\"" << pCur->getData().getName() << "\",";
			outfile << pCur->getData().getAbsences();
			if (pCur->getData().getAbsences() != 0) {
				string temp = "";
				pCur->getData().getAbsenceDates().peek(temp); //Gets most recent absence
				outfile << endl << "Most Recent Absence: " << temp;
			}
			if (pCur->getNext() != nullptr)
				outfile << endl << endl;

			pCur = pCur->getNext();
		}

		outfile.close();
		break;
	}
	case 2: {
		Node<T>* pCur = list->getHead();
		success = true;
		outfile.open("chosenStudentsReport.txt", ios::out);

		cout << "Enter a number to get students equal or greater than that number of absences" << endl;
		cin >> num;

		outfile << "Greater than or equal to " << num << (num == 1 ? " absence:" : " absences:") << endl << "Name,Absences"; //Ternary operator for grammatical purposes
		while (pCur != nullptr) {
			if (pCur->getData().getAbsences() >= num) 
				outfile << endl << "\"" << pCur->getData().getName() << "\"," << pCur->getData().getAbsences();
			
			pCur = pCur->getNext();
		}

		outfile.close();
		break;
	}
	default:
		cout << "Invalid input!" << endl << endl;
		break;
	}

	return success;
}