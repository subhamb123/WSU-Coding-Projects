/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 5 - Grocery Store Simulation               *
* Date: 3/11/2021                                                       *
* Description: This program simulates grocery store lanes.              *
************************************************************************/

#include "header.hpp"
#include "QueueNode.hpp"
#include "Queue.hpp"
#include "Test.hpp"

int main() {
	srand((unsigned int)time(nullptr)); //Initializes random
	
	//Creates objects
	Queue express, normal;
	Data data;

	int duration = -1, elapsed = 0, customerNumber = 1, totService = 0, expService = 0, normService = 0;

	while (duration < 0) {
		cout << "How many minutes do you want to run this simulation?" << endl;
		cin >> duration;
		cin.ignore(); //Eats up newline
	}

	cout << endl;

	int expressNum = (rand() % 5) + 1, normalNum = (rand() % 6) + 3; //Generates 1-5 for express and 3-8 for normal

	while (elapsed <= duration) {
		//Checks if a day has passed to reset customer numbers
		if (elapsed != 0 && elapsed % 1440 == 0) {
			cout << "One day has passed. Customer numbers have been reset." << endl << endl;
			customerNumber = 1;
		}
		
		//Checks if enough time has passed for a customer to arrive in the express lane
		if (elapsed == expressNum) {
			cout << "Customer " << customerNumber << " arrived at minute " << expressNum << " in the express lane." << endl;
			expressNum = (rand() % 5) + 1; //Generates random service time

			//Adds up all service times before current customer
			QueueNode* pCur = express.getHeadPtr();
			while (pCur != nullptr) {
				totService += express.getHeadPtr()->getData()->getService();
				pCur = pCur->getNextPtr();
			}

			Data* customer = new Data(customerNumber, expressNum, totService + expressNum); //Allocates new customer to heap
			express.enqueue(customer); //Enqueues customer to the queue
			expressNum = (rand() % 5) + 1 + elapsed; //Generates new random arrival time for next customer.
			customerNumber++; //Increments customer number
			totService = 0;
		}

		//Checks if enough time has passed for a customer to arrive in the normal lane
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

		//Checks if enough time has passed for a service to be complete in the express lane.
		if (!express.isEmpty() && expService == express.getHeadPtr()->getData()->getService()) {
			data = express.dequeue(); //Dequeues customer from the queue
			cout << "Customer " << data.getNumber() << " is done and spent " << data.getTotal() << " minutes in the express lane." << endl;
			expService = 0; //Resets timer that checks if enough time has passed for a service to be complete.
		}

		//Checks if enough time has passed for a service to be complete in the normal lane.
		if (!normal.isEmpty() && normService == normal.getHeadPtr()->getData()->getService()) {
			data = normal.dequeue();
			cout << "Customer " << data.getNumber() << " is done and spent " << data.getTotal() << " minutes in the normal lane." << endl;
			normService = 0;
		}

		//Both queues are printed every 10 minutes.
		if (duration != 0 && elapsed != 0 && elapsed % 10 == 0) {
			cout << endl << "Snapshot of queues " << elapsed << " minutes in." << endl << endl << "Express queue:" << endl << endl;
			express.printQueue();
			cout << "Normal queue:" << endl << endl;
			normal.printQueue();
			cout << "Press enter to continue" << endl;
			cin.ignore(); //Accepts newline as input
			system("cls"); //Clears the screen
		}

		elapsed++; //Increments by a minute

		//If there is a customer at the head of the queue, service time is counted.
		if (!express.isEmpty())
			expService++;
		if (!normal.isEmpty())
			normService++;
	}

	cout << "Simulation over. Here are some test cases." << endl << endl;

	Test test;

	//Test cases
	test.testEnqueueEmpty();
	test.testEnqueueOneNode();
	test.testDequeueOneNode();
	test.testDequeueTwoNodes();
	cout << "Press enter to continue" << endl;
	cin.ignore();
	system("cls");
	test.dayRun();

	return 0;
}