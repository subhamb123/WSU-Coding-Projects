#include "Queue.hpp"

Queue::Queue(QueueNode* pNewHead, QueueNode* pNewTail) {
	mpHead = pNewHead;
	mpTail = pNewTail;
}

Queue::~Queue() {
	while (!isEmpty())
		dequeue();
}

bool Queue::enqueue(string name) {
	bool success = false;
	QueueNode* pMem = new QueueNode(name);

	if (pMem != nullptr) {
		success = true;

		if (mpHead == nullptr) {
			mpHead = mpTail = pMem;
		}
		else {
			mpTail->setNextPtr(pMem); //same as mpTail->mpNext = pMem
			mpTail = pMem;
		}
	}

	return success;
}

string Queue::dequeue() {
	QueueNode* pTemp = mpHead;
	string data = "";

	if (mpHead == mpTail) {
		mpHead = mpTail = nullptr;
	}
	else {
		mpHead = mpHead->getNextPtr();
	}

	data = pTemp->getData();
	delete pTemp; //Invokes default destructor and this doesn't connect to anything else, so default is fine.
	return data;
}

bool Queue::isEmpty() {
	return mpHead == nullptr;
}

QueueNode* Queue::getHeadPtr() const {
	return mpHead;
}

void Queue::printQueueRecursive(QueueNode* pCur) {
	if (pCur == nullptr)
		;
	else {
		cout << pCur->getData() << endl;
		printQueueRecursive(pCur->getNextPtr());
	}
}