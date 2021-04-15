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
#include "TransactionNode.hpp"

//Classes
class BST {
public:
	BST();
	~BST();
	void setRoot(Node* pRoot);
	Node* getRoot() const;
	void insert(int units, string data);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();
private:
	void destroyTree(Node* pTree);
	void insert(Node*& pT, int units, string data);
	void inOrderTraversal(Node* pTree);
	Node* mpRoot;
};