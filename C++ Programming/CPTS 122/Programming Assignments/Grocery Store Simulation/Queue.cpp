/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 5 - Grocery Store Simulation               *
* Date: 3/11/2021                                                       *
* Description: This program simulates grocery store lanes.              *
************************************************************************/

#include "Queue.hpp"

/****************************************************************
* Class Function: Queue()                                       *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Constructor that initializes the variables       *
* Input parameters: 2 QueueNode*                                *
* Returns: Nothing                                              *
* Preconditions: 2 QueueNode*                                   *
* Postconditions: An object has been created                    *
*****************************************************************/
Queue::Queue(QueueNode* pNewHead, QueueNode* pNewTail) {
	pHead = pNewHead;
	pTail = pNewTail;
}

/****************************************************************
* Class Function: ~Queue()                                      *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Destructor that doesn't do anything              *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
Queue::~Queue() {

}

/****************************************************************
* Class Function: enqueue()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Enqueues the data into the queue                 *
* Input parameters: Data*                                       *
* Returns: Nothing                                              *
* Preconditions: Data*                                          *
* Postconditions: The customer has been queued.                 *
*****************************************************************/
void Queue::enqueue(Data* customer) {
	QueueNode* pMem = new QueueNode(customer);

	if (pMem != nullptr) {

		if (pHead == nullptr) {
			pHead = pTail = pMem;
		}
		else {
			pTail->setNextPtr(pMem); 
			pTail = pMem;
		}
	}
}

/****************************************************************
* Class Function: dequeue()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Dequeues the top node from the queue             *
* Input parameters: None                                        *
* Returns: Data                                                 *
* Preconditions: None                                           *
* Postconditions: Top node has been removed and returned        *
*****************************************************************/
Data Queue::dequeue() {
	QueueNode* pTemp = pHead;

	Data customer;

	if (pHead == pTail) {
		pHead = pTail = nullptr;
	}
	else {
		pHead =pHead->getNextPtr();
	}

	customer.setNumber(pTemp->getData()->getNumber());
	customer.setService(pTemp->getData()->getService());
	customer.setTotal(pTemp->getData()->getTotal());
	delete pTemp;
	return customer;
}

/****************************************************************
* Class Function: isEmpty()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Checks if queue is empty                         *
* Input parameters: None                                        *
* Returns: boolean                                              *
* Preconditions: None                                           *
* Postconditions: Boolean has been returned                     *
*****************************************************************/
bool Queue::isEmpty() {
	return pHead == nullptr;
}

/****************************************************************
* Class Function: getHeadPtr()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Gets the head pointer of the queue               *
* Input parameters: None                                        *
* Returns: QueueNode*                                           *
* Preconditions: None                                           *
* Postconditions: The head pointer has been returned            *
*****************************************************************/
QueueNode* Queue::getHeadPtr() const {
	return pHead;
}

/****************************************************************
* Class Function: printQueue()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Prints the queue                                 *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: Queue has been printed                        *
*****************************************************************/
void Queue::printQueue() {
	QueueNode* pCur = pHead;
	while (pCur != NULL) {
		cout << "Customer Number: " << pCur->getData()->getNumber() << endl << "Service Time: " << pCur->getData()->getService() << endl << "Total Time: " << pCur->getData()->getTotal() << endl << endl;
		pCur = pCur->getNextPtr();
	}
}