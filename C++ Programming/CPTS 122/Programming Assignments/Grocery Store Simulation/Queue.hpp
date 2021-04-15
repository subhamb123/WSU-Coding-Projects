/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 5 - Grocery Store Simulation               *
* Date: 3/11/2021                                                       *
* Description: This program simulates grocery store lanes.              *
************************************************************************/

//Guard Code
#pragma once

//Header Files
#include "header.hpp"
#include "QueueNode.hpp"

//Classes
class Queue {
public:
	Queue(QueueNode* pNewHead = nullptr, QueueNode* pNewTail = nullptr);
	~Queue();
	void enqueue(Data* customer);
	Data dequeue();
	bool isEmpty();
	QueueNode* getHeadPtr() const;
	void printQueue();
private:
    QueueNode* pHead;
    QueueNode* pTail;
};