/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 6 - Morse Code Lookup BST                  *
* Date: 3/19/2021                                                       *
* Description: This program translates character to morse code using BST*
************************************************************************/

//Guard Code
#pragma once

//Header Files
#include "BSTNode.hpp"

//Classes
template <typename character, typename code>
class BST {
public:
	BST();
	~BST();
	code search(character c);
	void print();

private:
	void insert(BSTNode<character, code>* pTree, code code, character c);
	code search(BSTNode<character, code>* pTree, character c);
	void print(BSTNode<character, code>* pTree);
	void delNode(BSTNode<character, code>* pTree);
	BSTNode<character, code>* pRoot;
};

/****************************************************************
* Class Function: BST()                                         *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Constructor that fills the tree with translations*
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been created                    *
*****************************************************************/
template <typename character, typename code>
BST<character, code>::BST() {
	pRoot = nullptr;
	character data;
	code translation;
	fstream infile;
	infile.open("MorseTable.txt", ios::in);
	while (!infile.eof()) {
		infile >> data;
		infile >> translation;
		insert(pRoot, translation, data);
	}

	infile.close();
}

/****************************************************************
* Class Function: ~BST()                                        *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Deconstructor that deletes every node in the tree*
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
template <typename character, typename code>
BST<character, code>::~BST() {
	delNode(pRoot);
}

/****************************************************************
* Class Function: search()                                      *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Intermediary function as pRoot is private        *
* Input parameters: char                                        *
* Returns: string                                               *
* Preconditions: char                                           *
* Postconditions: The translation has been returned             *
*****************************************************************/
template <typename character, typename code>
code BST<character, code>::search(character c) {
	return search(pRoot, c);
}

/****************************************************************
* Class Function: print()                                       *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Intermediary function as pRoot is private        *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The tree has been printed                     *
*****************************************************************/
template <typename character, typename code>
void BST<character, code>::print() {
	print(pRoot);
}

/****************************************************************
* Class Function: insert()                                      *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Inserts nodes in tree based on ascii value       *
* Input parameters: BSTNode*, string, char                      *
* Returns: Nothing                                              *
* Preconditions: BSTNode*, string, char                         *
* Postconditions: A node has been inserted into the tree        *
*****************************************************************/
template <typename character, typename code>
void BST<character, code>::insert(BSTNode<character, code>* pTree, code translation, character c) {
	if (pTree == nullptr) {
		pRoot = new BSTNode<character, code>(c, translation);
	}
	else {
		if (c < pTree->getCharacter()) {
			if (pTree->getLeftPtr() == nullptr)
				pTree->setLeftPtr(new BSTNode<character, code>(c, translation));
			else
				insert(pTree->getLeftPtr(), translation, c);
		}
		else if (c > pTree->getCharacter()) {
			if (pTree->getRightPtr() == nullptr)
				pTree->setRightPtr(new BSTNode<character, code>(c, translation));
			else
				insert(pTree->getRightPtr(), translation, c);
		}
	}
}

/****************************************************************
* Class Function: search()                                      *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Searches translation for character               *
* Input parameters: BSTNode* and char                           *
* Returns: string                                               *
* Preconditions: BSTNode* and char                              *
* Postconditions: Translation has been returned                 *
*****************************************************************/
template <typename character, typename code>
code BST<character, code>::search(BSTNode<character, code>* pTree, character c) {
	code s;
	if (pTree != nullptr) {
		if (pTree->getCharacter() == c)
			return pTree->getCode();
		s = search(pTree->getLeftPtr(), c);
		if (typeid(code) == typeid(string) && s == "")
			s = search(pTree->getRightPtr(), c);
	}

	return s;
}

/****************************************************************
* Class Function: print()                                       *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Prints tree using inorder traversal              *
* Input parameters: BSTNode*                                    *
* Returns: Nothing                                              *
* Preconditions: BSTNode*                                       *
* Postconditions: The tree has been printed                     *
*****************************************************************/
template <typename character, typename code>
void BST<character, code>::print(BSTNode<character, code>* pTree) {
	if (pTree != nullptr) {
		print(pTree->getLeftPtr());
		cout << pTree->getCharacter() << " " << pTree->getCode() << endl;
		print(pTree->getRightPtr());
	}
}

/****************************************************************
* Class Function: delNode()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Deletes nodes using postorder traversal          *
* Input parameters: BSTNode*                                    *
* Returns: Nothing                                              *
* Preconditions: BSTNode*                                       *
* Postconditions: A node has been deleted                       *
*****************************************************************/
template <typename character, typename code>
void BST<character, code>::delNode(BSTNode<character, code>* pTree) {
	if (pTree != nullptr) {
		delNode(pTree->getLeftPtr());
		delNode(pTree->getRightPtr());
		delete pTree;
	}
}