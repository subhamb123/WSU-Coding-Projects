#pragma once

#include "Node.h"

class BST {
public:
	BST();
	~BST();
	void insertNode(string newData);
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

private:
	void insertNode(Node* pTree, string newData);
	void inOrderTraversal(Node* pTree);
	void preOrderTraversal(Node* pTree);
	void postOrderTraversal(Node* pTree);
	bool isEmpty();
	void destroyTree(Node* pTree);
	Node* mpRoot;
};

ostream& operator<< (ostream& lhs, BST& rhs);