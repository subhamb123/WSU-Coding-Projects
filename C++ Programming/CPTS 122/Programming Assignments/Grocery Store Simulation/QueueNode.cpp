/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 5 - Grocery Store Simulation               *
* Date: 3/11/2021                                                       *
* Description: This program simulates grocery store lanes.              *
************************************************************************/

#include "QueueNode.hpp"

/****************************************************************
* Class Function: QueueNode()                                   *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Constructor that initializes the variables       *
* Input parameters: Data* and QueueNode*                        *
* Returns: Nothing                                              *
* Preconditions: Data* and QueueNode*                           *
* Postconditions: An object has been created                    *
*****************************************************************/
QueueNode::QueueNode(const Data* customer, QueueNode* pNext) {
	pData = new Data();
	pData->setNumber(customer->getNumber());
	pData->setService(customer->getService());
	pData->setTotal(customer->getTotal());
	this->pNext = pNext;
}

/****************************************************************
* Class Function: ~QueueNode()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Destructor that deletes pData; it is on the heap *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
QueueNode::~QueueNode() {
	delete pData;
}

/****************************************************************
* Class Function: setNextPtr()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets the next pointer in the queue               *
* Input parameters: QueueNode*                                  *
* Returns: Nothing                                              *
* Preconditions: QueueNode*                                     *
* Postconditions: The next pointer has been set                 *
*****************************************************************/
void QueueNode::setNextPtr(QueueNode* const pNext) {
	this->pNext = pNext;
}

/****************************************************************
* Class Function: getNextPtr()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Gets the next pointer in the queue               *
* Input parameters: None                                        *
* Returns: QueueNode*                                           *
* Preconditions: None                                           *
* Postconditions: The next pointer has been returned            *
*****************************************************************/
QueueNode* QueueNode::getNextPtr() const {
	return pNext;
}

/****************************************************************
* Class Function: getData()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Gets the data in the node                        *
* Input parameters: None                                        *
* Returns: Data*                                                *
* Preconditions: None                                           *
* Postconditions: The data has been returned                    *
*****************************************************************/
Data* QueueNode::getData() const {
	return pData;
}

/****************************************************************
* Class Function: Data()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Constructor that initializes the variables       *
* Input parameters: 3 int                                       *
* Returns: Nothing                                              *
* Preconditions: 3 int                                          *
* Postconditions: An object has been created                    *
*****************************************************************/
Data::Data(int number, int service, int total) {
	customerNumber = number;
	serviceTime = service;
	totalTime = total;
}

/****************************************************************
* Class Function: ~Data()                                       *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Destructor that doesn't do anything              *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
Data::~Data() {

}

/****************************************************************
* Class Function: setNumber()                                   *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets the customer number in the object           *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: The customer number has been set              *
*****************************************************************/
void Data::setNumber(int number) {
	customerNumber = number;
}

/****************************************************************
* Class Function: setService()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets the service time in the object              *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: The service time has been set                 *
*****************************************************************/
void Data::setService(int service) {
	serviceTime = service;
}

/****************************************************************
* Class Function: setTotal()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets the total time in the object                *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: The total time has been set                   *
*****************************************************************/
void Data::setTotal(int total) {
	totalTime = total;
}

/****************************************************************
* Class Function: getNumber()                                   *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Gets the customer number in the object           *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Customer number has been returned.            *
*****************************************************************/
int Data::getNumber() const {
	return customerNumber;
}

/****************************************************************
* Class Function: getService()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Gets the service time in the object              *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Service time has been returned.               *
*****************************************************************/
int Data::getService() const {
	return serviceTime;
}

/****************************************************************
* Class Function: getTotal()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Gets the total time in the object                *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Total time has been returned.                 *
*****************************************************************/
int Data::getTotal() const {
	return totalTime;
}