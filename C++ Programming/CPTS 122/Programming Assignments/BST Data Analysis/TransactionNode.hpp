/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 8 - Data Analysis using Binary Search Trees*
* Date: 4/10/2021                                                       *
* Description: This program simulates product ownership using BST       *
************************************************************************/

//Guard Code
#pragma once

//Header Files
#include "Node.hpp"

//Classes
class TransactionNode : public Node {
public:
	TransactionNode(string data = "", int units = 0) : Node(data) {
		mUnits = units;
	}
	~TransactionNode();
	void setUnits(int units);
	int getUnits() const;
	void printData();
private:
	int mUnits;
};