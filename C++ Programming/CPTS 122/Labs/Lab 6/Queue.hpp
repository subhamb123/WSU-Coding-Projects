#pragma once

#include <iostream>
#include "QueueNode.hpp"

class Queue {
public:
	Queue(QueueNode* pNewHead = nullptr, QueueNode* pNewTail = nullptr);
	~Queue();
	bool enqueue(string name);
	string dequeue();
	bool isEmpty();
	QueueNode* getHeadPtr() const;
	void printQueueRecursive(QueueNode* pCur);
private:
	QueueNode* mpHead;
	QueueNode* mpTail;
};