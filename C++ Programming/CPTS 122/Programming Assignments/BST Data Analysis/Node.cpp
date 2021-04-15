/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 8 - Data Analysis using Binary Search Trees*
* Date: 4/10/2021                                                       *
* Description: This program simulates product ownership using BST       *
************************************************************************/

#include "Node.hpp"

/****************************************************************
* Class Function: Node()                                        *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Constructor that initializes data                *
* Input parameters: string                                      *
* Returns: Nothing                                              *
* Preconditions: string                                         *
* Postconditions: An object has been created                    *
*****************************************************************/
Node::Node(string data) {
	mData = data;
	mpLeft = mpRight = nullptr;
}

/****************************************************************
* Class Function: ~Node()                                       *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Destructor that does nothing                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
Node::~Node() {
	//What nodes to delete is managed when the tree is deleted.
}

/****************************************************************
* Class Function: setData()                                     *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Sets the data                                    *
* Input parameters: string                                      *
* Returns: Nothing                                              *
* Preconditions: string                                         *
* Postconditions: The data has been modified                    *
*****************************************************************/
void Node::setData(string data) {
	mData = data;
}

/****************************************************************
* Class Function: setLeft()                                     *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Sets left pointer                                *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: The left pointer has been modified            *
*****************************************************************/
void Node::setLeft(Node* pLeft) {
	mpLeft = pLeft;
}

/****************************************************************
* Class Function: setRight()                                    *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Sets right pointer                               *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: The right pointer has been modified           *
*****************************************************************/
void Node::setRight(Node* pRight) {
	mpRight = pRight;
}

/****************************************************************
* Class Function: getData()                                     *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Returns the data                                 *
* Input parameters: None                                        *
* Returns: string                                               *
* Preconditions: None                                           *
* Postconditions: Data has been returned                        *
*****************************************************************/
string Node::getData() const {
	return mData;
}

/****************************************************************
* Class Function: getLeft()                                     *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Returns left pointer                             *
* Input parameters: None                                        *
* Returns: Node*&                                               *
* Preconditions: None                                           *
* Postconditions: Left pointer has been returned                *
*****************************************************************/
Node*& Node::getLeft() {
	return mpLeft;
}

/****************************************************************
* Class Function: getRight()                                    *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Returns right pointer                            *
* Input parameters: None                                        *
* Returns: Node*&                                               *
* Preconditions: None                                           *
* Postconditions: Right pointer has been returned               *
*****************************************************************/
Node*& Node::getRight() {
	return mpRight;
}