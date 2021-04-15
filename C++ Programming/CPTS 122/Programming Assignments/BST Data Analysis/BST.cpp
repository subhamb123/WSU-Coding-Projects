/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 8 - Data Analysis using Binary Search Trees*
* Date: 4/10/2021                                                       *
* Description: This program simulates product ownership using BST       *
************************************************************************/

#include "BST.hpp"

/****************************************************************
* Class Function: BST()                                         *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Constructor that initializes the data            *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been created                    *
*****************************************************************/
BST::BST() {
	mpRoot = nullptr;
}

/****************************************************************
* Class Function: ~BST()                                        *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Destructor that dynamically destroys the BST     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
BST::~BST() {
	destroyTree(mpRoot);
}

/****************************************************************
* Class Function: setRoot()                                     *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Sets the root pointer                            *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: The root pointer has been modified            *
*****************************************************************/
void BST::setRoot(Node* pRoot) {
	mpRoot = pRoot;
}

/****************************************************************
* Class Function: getRoot()                                     *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Returns the root pointer                         *
* Input parameters: None                                        *
* Returns: Node*                                                *
* Preconditions: None                                           *
* Postconditions: The root pointer has been returned            *
*****************************************************************/
Node* BST::getRoot() const {
	return mpRoot;
}

/****************************************************************
* Class Function: insert()                                      *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Calls the private insert() function              *
* Input parameters: int and string                              *
* Returns: Nothing                                              *
* Preconditions: int and string                                 *
* Postconditions: The private insert() function has been called *
*****************************************************************/
void BST::insert(int units, string data) {
	insert(mpRoot, units, data);
}

/****************************************************************
* Class Function: inOrderTraversal()                            *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Calls the private inOrderTraversal() function    *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The private function has been called          *
*****************************************************************/
void BST::inOrderTraversal() {
	inOrderTraversal(mpRoot);
}

/****************************************************************
* Class Function: findSmallest()                                *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Finds the node with smallest units               *
* Input parameters: None                                        *
* Returns: TransactionNode&                                     *
* Preconditions: None                                           *
* Postconditions: The node with smallest units has been returned*
*****************************************************************/
TransactionNode& BST::findSmallest() {
	Node* pCur = mpRoot;
	while (pCur->getLeft() != nullptr) //Left is where the smallest data is
		pCur = pCur->getLeft();

	return *(dynamic_cast<TransactionNode*> (pCur)); //Derefrences the casted pointer to match return type
}

/****************************************************************
* Class Function: findLargest()                                 *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Finds the node with largest units                *
* Input parameters: None                                        *
* Returns: TransactionNode&                                     *
* Preconditions: None                                           *
* Postconditions: The node with largest units has been returned *
*****************************************************************/
TransactionNode& BST::findLargest() {
	Node* pCur = mpRoot;
	while (pCur->getRight() != nullptr) //Right is where the largest data is
		pCur = pCur->getRight();

	return *(dynamic_cast<TransactionNode*> (pCur));
}

/****************************************************************
* Class Function: destroyTree()                                 *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Recursively destroys the nodes in the tree       *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: A node has been destroyed                     *
*****************************************************************/
void BST::destroyTree(Node* pTree) {
	if (pTree != nullptr) {
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

/****************************************************************
* Class Function: insert()                                      *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Inserts new data into the tree                   *
* Input parameters: Node*&, int, string                         *
* Returns: Nothing                                              *
* Preconditions: Node*&, int, string                            *
* Postconditions: New data has been inserted                    *
*****************************************************************/
void BST::insert(Node*& pT, int units, string data) {
	if (pT == nullptr)
		pT = new TransactionNode(data, units);
	
	else {
		if (units < (dynamic_cast<TransactionNode*> (pT))->getUnits()) //Casted to get a function found in a derived class
			insert(pT->getLeft(), units, data);
		
		else if (units > (dynamic_cast<TransactionNode*> (pT))->getUnits())
			insert(pT->getRight(), units, data);
	}
}

/****************************************************************
* Class Function: inOrderTraversal()                            *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Prints node's data recursively                   *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: A node's data has been printed                *
*****************************************************************/
void BST::inOrderTraversal(Node* pTree) {
	if (pTree != nullptr) {
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}