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
#include "header.hpp"

//Classes
template <typename character, typename code>
class BSTNode {
public:
	BSTNode(character character, code code);
	~BSTNode();
	character getCharacter();
	code getCode();
	BSTNode<character, code>* getLeftPtr();
	BSTNode<character, code>* getRightPtr();
	void setLeftPtr(BSTNode<character, code>* ptr);
	void setRightPtr(BSTNode<character, code>* ptr);

private:
	character data;
	code translation;
	BSTNode<character, code>* pLeft;
	BSTNode<character, code>* pRight;
};

/****************************************************************
* Class Function: BSTNode()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Constructor that initializes the variables       *
* Input parameters: char and string                             *
* Returns: Nothing                                              *
* Preconditions: char and string                                *
* Postconditions: An object has been created                    *
*****************************************************************/
template <typename character, typename code>
BSTNode<character, code>::BSTNode(character data, code translation) {
	this->data = data;
	this->translation = translation;
	pLeft = pRight = nullptr;
}

/****************************************************************
* Class Function: ~BSTNode()                                    *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Deconstructor that does nothing                  *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
template <typename character, typename code>
BSTNode<character, code>::~BSTNode() {
	//What nodes to delete is managed when the tree is deleted.
}

/****************************************************************
* Class Function: getCharacter()                                *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns character                                *
* Input parameters: None                                        *
* Returns: char                                                 *
* Preconditions: None                                           *
* Postconditions: The node character has been returned          *
*****************************************************************/
template <typename character, typename code>
character BSTNode<character, code>::getCharacter() {
	return data;
}

/****************************************************************
* Class Function: getCode()                                     *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns the morse code                           *
* Input parameters: None                                        *
* Returns: string                                               *
* Preconditions: None                                           *
* Postconditions: The translation has been returned             *
*****************************************************************/
template <typename character, typename code>
code BSTNode<character, code>::getCode() {
	return translation;
}

/****************************************************************
* Class Function: getLeftPtr()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns left pointer                             *
* Input parameters: None                                        *
* Returns: BSTNode*                                             *
* Preconditions: None                                           *
* Postconditions: The left pointer has been returned            *
*****************************************************************/
template <typename character, typename code>
BSTNode<character, code>* BSTNode<character, code>::getLeftPtr() {
	return pLeft;
}

/****************************************************************
* Class Function: getRightPtr()                                 *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Returns right pointer                            *
* Input parameters: None                                        *
* Returns: BSTNode*                                             *
* Preconditions: None                                           *
* Postconditions: The right pointer has been returned           *
*****************************************************************/
template <typename character, typename code>
BSTNode<character, code>* BSTNode<character, code>::getRightPtr() {
	return pRight;
}

/****************************************************************
* Class Function: setLeftPtr()                                  *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets the left pointer                            *
* Input parameters: BSTNode*                                    *
* Returns: Nothing                                              *
* Preconditions: BSTNode*                                       *
* Postconditions: The left pointer has been set                 *
*****************************************************************/
template <typename character, typename code>
void BSTNode<character, code>::setLeftPtr(BSTNode<character, code>* ptr) {
	pLeft = ptr;
}

/****************************************************************
* Class Function: setRightPtr()                                 *
* Date Created: 2/26/2021                                       *
* Date Last Modified: 2/26/2021                                 *
* Description: Sets the right pointer                           *
* Input parameters: BSTNode*                                    *
* Returns: Nothing                                              *
* Preconditions: BSTNode*                                       *
* Postconditions: The right pointer has been set                *
*****************************************************************/
template <typename character, typename code>
void BSTNode<character, code>::setRightPtr(BSTNode<character, code>* ptr) {
	pRight = ptr;
}