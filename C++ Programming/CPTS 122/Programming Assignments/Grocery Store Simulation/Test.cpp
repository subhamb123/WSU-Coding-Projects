/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 5 - Grocery Store Simulation               *
* Date: 3/11/2021                                                       *
* Description: This program simulates grocery store lanes.              *
************************************************************************/

#include "Test.hpp"

/****************************************************************
* Class Function: testEnqueueEmpty()                            *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Tests enqueue when queue is empty                *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: Enqueue has been tested                       *
*****************************************************************/
void Test::testEnqueueEmpty() {
	cout << "Test enqueue empty" << endl << endl;
	Queue q;
	Data d = { 10, 5, 20 };
	q.enqueue(&d);
	q.printQueue();
}

/****************************************************************
* Class Function: testEnqueueOneNode()                          *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Tests enqueue when queue has one node            *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: Enqueue has been tested                       *
*****************************************************************/
void Test::testEnqueueOneNode() {
	cout << "Test enqueue one node" << endl << endl;
	Queue q;
	Data d1 = { 10, 5, 20 }, d2 = { 15, 2, 25 };
	q.enqueue(&d1);
	q.enqueue(&d2);
	q.printQueue();
}

/****************************************************************
* Class Function: testDequeueOneNode()                          *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Tests dequeue when queue has one node            *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: Dequeue has been tested                       *
*****************************************************************/
void Test::testDequeueOneNode() {
	cout << "Test dequeue one node" << endl << endl;
	Queue q;
	Data d = { 10, 5, 20 };
	q.enqueue(&d);
	cout << "Before" << endl;
	q.printQueue();
	d = q.dequeue();
	cout << "After" << endl << endl;
	q.printQueue();
	cout << "But data is returned and can be seen in implementation." << endl << endl;
}

/****************************************************************
* Class Function: testDequeueTwoNodes()                         *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Tests dequeue when queue has two nodes           *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: Dequeue has been tested                       *
*****************************************************************/
void Test::testDequeueTwoNodes() {
	cout << "Test dequeue two nodes" << endl << endl;
	Queue q;
	Data d1 = { 10, 5, 20 }, d2 = { 15, 2, 25 };
	q.enqueue(&d1);
	q.enqueue(&d2);
	cout << "Before" << endl;
	q.printQueue();
	d1 = q.dequeue();
	cout << "After" << endl << endl;
	q.printQueue();
	cout << "But data is returned and can be seen in implementation." << endl << endl;
}

/****************************************************************
* Class Function: dayRun()                                      *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Tests simulation with a full day cycle           *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The simulation has been tested                *
*****************************************************************/
void Test::dayRun() {
	srand((unsigned int)time(nullptr));

	Queue express, normal;
	Data data;
	int elapsed = 0, customerNumber = 1, totService = 0, expService = 0, normService = 0;

	int expressNum = (rand() % 5) + 1, normalNum = (rand() % 6) + 3;

	while (elapsed <= 1440) {
		if (elapsed == expressNum) {
			cout << "Customer " << customerNumber << " arrived at minute " << expressNum << " in the express lane." << endl;
			expressNum = (rand() % 5) + 1;

			QueueNode* pCur = express.getHeadPtr();
			while (pCur != nullptr) {
				totService += express.getHeadPtr()->getData()->getService();
				pCur = pCur->getNextPtr();
			}

			Data* customer = new Data(customerNumber, expressNum, totService + expressNum);
			express.enqueue(customer);
			expressNum = (rand() % 5) + 1 + elapsed;
			customerNumber++;
			totService = 0;
		}

		if (elapsed == normalNum) {
			cout << "Customer " << customerNumber << " arrived at minute " << normalNum << " in the normal lane." << endl;
			normalNum = (rand() % 6) + 3;

			QueueNode* pCur = normal.getHeadPtr();
			while (pCur != nullptr) {
				totService += normal.getHeadPtr()->getData()->getService();
				pCur = pCur->getNextPtr();
			}

			Data* customer = new Data(customerNumber, normalNum, totService + normalNum);
			normal.enqueue(customer);
			normalNum = (rand() % 6) + 3 + elapsed;
			customerNumber++;
			totService = 0;
		}

		if (!express.isEmpty() && expService == express.getHeadPtr()->getData()->getService()) {
			data = express.dequeue();
			cout << "Customer " << data.getNumber() << " is done and spent " << data.getTotal() << " minutes in the express lane." << endl;
			expService = 0;
		}

		if (!normal.isEmpty() && normService == normal.getHeadPtr()->getData()->getService()) {
			data = normal.dequeue();
			cout << "Customer " << data.getNumber() << " is done and spent " << data.getTotal() << " minutes in the normal lane." << endl;
			normService = 0;
		}

		if (elapsed != 0 && elapsed % 10 == 0) {
			cout << endl << "Snapshot of queues " << elapsed << " minutes in." << endl << endl << "Express queue:" << endl << endl;
			express.printQueue();
			cout << "Normal queue:" << endl << endl;
			normal.printQueue();
		}

		elapsed++;
		if (!express.isEmpty())
			expService++;
		if (!normal.isEmpty())
			normService++;
	}
}