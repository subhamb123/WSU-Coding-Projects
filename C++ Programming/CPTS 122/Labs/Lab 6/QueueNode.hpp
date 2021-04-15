#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class QueueNode {
public:
	QueueNode(const string& job = "");
	void setNextPtr(QueueNode* const pNext);
	QueueNode* getNextPtr() const;
	string getData() const;
private:
	string mPrintJob;
	QueueNode* mpNext;
};