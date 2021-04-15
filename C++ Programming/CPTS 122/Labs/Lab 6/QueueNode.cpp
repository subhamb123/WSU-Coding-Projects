#include "QueueNode.hpp"

QueueNode::QueueNode(const string& job) {
	mPrintJob = job;
	mpNext = nullptr;
}

void QueueNode::setNextPtr(QueueNode* const pNext) {
	mpNext = pNext;
}

QueueNode* QueueNode::getNextPtr() const {
	return mpNext;
}

string QueueNode::getData() const {
	return mPrintJob;
}