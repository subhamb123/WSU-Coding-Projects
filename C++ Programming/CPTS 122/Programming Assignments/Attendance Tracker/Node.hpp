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
#include "Data.hpp"

//Classes
template <class T>
class Node {
public:
	Node(T& data);
	~Node();
	Node<T>* getNext() const;
	Data& getData();
	void setNext(Node<T>* ptr);
private:
	Data studentData;
	Node<T>* pNext;
};

/****************************************************************
* Class Function: Node()                                        *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Constructor that initializes the variables       *
* Input parameters: T&                                          *
* Returns: Nothing                                              *
* Preconditions: T&                                             *
* Postconditions: An object has been created                    *
*****************************************************************/
template <class T>
Node<T>::Node(T& data) {
	studentData.setRecNum(data.getRecNum());
	studentData.setID(data.getID());
	studentData.setName(data.getName());
	studentData.setEmail(data.getEmail());
	studentData.setUnits(data.getUnits());
	studentData.setMajor(data.getMajor());
	studentData.setLevel(data.getLevel());
	studentData.setAbsences(data.getAbsences());
	studentData.setAbsenceDates(data.getAbsenceDates());
	pNext = nullptr;
}

/****************************************************************
* Class Function: :~Node()                                      *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Destructor that does nothing                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
template <class T>
Node<T>::~Node() {
	//What nodes to delete is managed when the list is deleted.
}

/****************************************************************
* Class Function: getNext()                                     *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Returns next pointer                             *
* Input parameters: None                                        *
* Returns: Node<T>*                                             *
* Preconditions: None                                           *
* Postconditions: Next pointer has been returned                *
*****************************************************************/
template <class T>
Node<T>* Node<T>::getNext() const {
	return pNext;
}

/****************************************************************
* Class Function: getData()                                     *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Returns the data                                 *
* Input parameters: None                                        *
* Returns: Data&                                                *
* Preconditions: None                                           *
* Postconditions: Data has been returned                        *
*****************************************************************/
template <class T>
Data& Node<T>::getData() {
	return studentData;
}

/****************************************************************
* Class Function: setNext()                                     *
* Date Created: 3/30/2021                                       *
* Date Last Modified: 3/30/2021                                 *
* Description: Sets the next pointer                            *
* Input parameters: Node<T>*                                    *
* Returns: Nothing                                              *
* Preconditions: Node<T>*                                       *
* Postconditions: The next pointer has been set                 *
*****************************************************************/
template <class T>
void Node<T>::setNext(Node<T>* ptr) {
	pNext = ptr;
}