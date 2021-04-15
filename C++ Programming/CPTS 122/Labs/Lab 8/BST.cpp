#include "BST.h"

BST::BST() {
	mpRoot = nullptr;
}

BST::~BST() {
	destroyTree(mpRoot);
}

void BST::insertNode(string newData) {
	insertNode(mpRoot, newData);
}

void BST::insertNode(Node* pTree, string newData) {
	if (pTree == nullptr) {
		mpRoot = new Node(newData);
	}
	else {
		if (newData < pTree->getData()) {
			if (pTree->getLeftPtr() == nullptr)
				pTree->setLeftPtr(new Node(newData));
			else
				insertNode(pTree->getLeftPtr(), newData);
		}
		else if (newData > pTree->getData()) {
			if (pTree->getRightPtr() == nullptr)
				pTree->setRightPtr(new Node(newData));
			else
				insertNode(pTree->getRightPtr(), newData);
		}
	}
}

void BST::inOrderTraversal() {
	inOrderTraversal(mpRoot);
}

void BST::inOrderTraversal(Node* pTree) {
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeftPtr());
		cout << *pTree;
		inOrderTraversal(pTree->getRightPtr());
	}
}

void BST::preOrderTraversal() {
	preOrderTraversal(mpRoot);
}

void BST::preOrderTraversal(Node* pTree) {
	if (pTree != nullptr) {
		cout << *pTree;
		preOrderTraversal(pTree->getLeftPtr());
		preOrderTraversal(pTree->getRightPtr());
	}
}

void BST::postOrderTraversal() {
	postOrderTraversal(mpRoot);
}

void BST::postOrderTraversal(Node* pTree) {
	if (pTree != nullptr) {
		postOrderTraversal(pTree->getLeftPtr());
		postOrderTraversal(pTree->getRightPtr());
		cout << *pTree;
	}
}

bool BST::isEmpty() {
	return mpRoot == nullptr;
}

void BST::destroyTree(Node* pTree) {
	if (pTree != nullptr) {
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}

ostream& operator<< (ostream& lhs, BST& rhs) {
	rhs.inOrderTraversal();
	lhs << endl << "----------" << endl;
	rhs.preOrderTraversal();
	lhs << endl << "----------" << endl;
	rhs.postOrderTraversal();
	return lhs;
}