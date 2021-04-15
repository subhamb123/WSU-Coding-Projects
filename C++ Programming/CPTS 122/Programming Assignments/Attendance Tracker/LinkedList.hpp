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
#include "Node.hpp"

//Classes
template <class T>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	Node<T>* getHead() const;
	void insertFront(Data& pNewData);
	void deleteList(Node<T>* pCur);
private:
	Node<T>* pHead;
};

/****************************************************************
* Class Function: LinkedList()                                  *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Constructor that loads data from file            *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been created                    *
*****************************************************************/
template <class T>
LinkedList<T>::LinkedList() {
	pHead = nullptr;
	Data data;
	string temp = "";
	int temp2 = 0;
	char temp3 = '\0';
	bool success = false;
	fstream infile;
	infile.open("classList.csv", ios::in);

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

		insertFront(data);
	}

	infile.close();
}

/****************************************************************
* Class Function: ~LinkedList()                                 *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Destructor that deletes the list                 *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
template <class T>
LinkedList<T>::~LinkedList() {
	deleteList(pHead);
}

/****************************************************************
* Class Function: getHead()                                     *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Returns the front of the list                    *
* Input parameters: None                                        *
* Returns: Node<T>*                                             *
* Preconditions: None                                           *
* Postconditions: The front has been returned                   *
*****************************************************************/
template <class T>
Node<T>* LinkedList<T>::getHead() const {
	return pHead;
}

/****************************************************************
* Class Function: insertFront()                                 *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Inserts data to the front of the list            *
* Input parameters: Data&                                       *
* Returns: Nothing                                              *
* Preconditions: Data&                                          *
* Postconditions: The data has been inserted into the list      *
*****************************************************************/
template <class T>
void LinkedList<T>::insertFront(Data& pNewData) { 
	Node<T>* pMem = new Node<T>(pNewData);
	if (pMem != nullptr) {
		pMem->setNext(pHead);
		pHead = pMem;
	}
}

/****************************************************************
* Class Function: deleteList()                                  *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Recursively deletes the list                     *
* Input parameters: Node<T>*                                    *
* Returns: Nothing                                              *
* Preconditions: Node<T>*                                       *
* Postconditions: The list has been deleted                     *
*****************************************************************/
template <class T>
void LinkedList<T>::deleteList(Node<T>* pCur) {
	if (pCur != nullptr) {
		deleteList(pCur->getNext());
		delete pCur;
	}
	else
		pHead = nullptr;
}