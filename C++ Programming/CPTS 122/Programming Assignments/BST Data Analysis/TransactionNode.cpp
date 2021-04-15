/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 8 - Data Analysis using Binary Search Trees*
* Date: 4/10/2021                                                       *
* Description: This program simulates product ownership using BST       *
************************************************************************/

#include "TransactionNode.hpp"

/****************************************************************
* Class Function: ~TransactionNode()                            *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Destructor that does nothing                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
TransactionNode::~TransactionNode() {
	//What nodes to delete is managed when the tree is deleted.
}

/****************************************************************
* Class Function: setUnits()                                    *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Sets the units                                   *
* Input parameters: int                                         *
* Returns: Nothing                                              *
* Preconditions: int                                            *
* Postconditions: Units have been modified                      *
*****************************************************************/
void TransactionNode::setUnits(int units) {
	mUnits = units;
}

/****************************************************************
* Class Function: getUnits()                                    *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Returns the units                                *
* Input parameters: None                                        *
* Returns: int                                                  *
* Preconditions: None                                           *
* Postconditions: Units have been returned                      *
*****************************************************************/
int TransactionNode::getUnits() const {
	return mUnits;
}

/****************************************************************
* Class Function: printData()                                   *
* Date Created: 4/10/2021                                       *
* Date Last Modified: 4/10/2021                                 *
* Description: Prints the information of a product              *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: The info has been printed.                    *
*****************************************************************/
void TransactionNode::printData() {
	cout << "Product: " << mData << ", Units: " << mUnits << endl;
}