/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 223                                                       *
* Programming Assignment: PA 1 - Learning Linux Commands Matching Game  *
*                                and C++ Review                         *
* Date: 8/30/2021                                                       *
* Description: This program is a matching game to learn Linux commands. *
************************************************************************/

#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::stoi;
using std::ws;
using std::string;
using std::fstream;
using std::ios;

class Profile {
public:
    Profile(string name = "", int points = 0);
    ~Profile();
    string getName();
    int getPoints();
    void setName(string name);
    void setPoints(int points);

private:
    string name;
    int points;
};

template <class command, class description>
class Node {
public:
    Node(command c, description d, Node<command, description>* pNext = nullptr);
    ~Node();
    command getCommand();
    description getDescription();
    Node<command, description>* getNext();
    void setCommand(command c);
    void setDescription(description d);
    void setNext(Node<command, description>* pNext);

private:
    command c;
    description d;
    Node<command, description>* pNext;
};

template <class command, class description>
class List {
public:
    List(Node<command, description>* pRoot = nullptr);
    ~List();
    Node<command, description>* getRoot();
    void setRoot(Node<command, description>* pRoot);
    void insertFront(command c, description d);
    void delNode(command c);
    void delList(Node<command, description>* pRoot);

private:
    Node<command, description>* pRoot;
};

/****************************************************************
* Class Function: Node()                                        *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: A constructor                                    *
* Input parameters: command, description, Node*                 *
* Returns: Nothing                                              *
* Preconditions: command, description, Node*                    *
* Postconditions: An object has been initialized                *
*****************************************************************/
template <class command, class description>
Node<command, description>::Node(command c, description d, Node<command, description>* pNext) {
    this->c = c;
    this->d = d;
}

/****************************************************************
* Class Function: ~Node()                                       *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: A destructor                                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
template <class command, class description>
Node<command, description>::~Node() {

}

/****************************************************************
* Class Function: getCommand()                                  *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Returns command                                  *
* Input parameters: None                                        *
* Returns: command                                              *
* Preconditions: None                                           *
* Postconditions: Command has been returned                     *
*****************************************************************/
template <class command, class description>
command Node<command, description>::getCommand() {
    return c;
}

/****************************************************************
* Class Function: getDescription()                              *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Returns description                              *
* Input parameters: None                                        *
* Returns: description                                          *
* Preconditions: None                                           *
* Postconditions: Description has been returned                 *
*****************************************************************/
template <class command, class description>
description Node<command, description>::getDescription() {
    return d;
}

/****************************************************************
* Class Function: getNext()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Returns next pointer                             *
* Input parameters: None                                        *
* Returns: Node*                                                *
* Preconditions: None                                           *
* Postconditions: Next pointer has been returned                *
*****************************************************************/
template <class command, class description>
Node<command, description>* Node<command, description>::getNext() {
    return pNext;
}

/****************************************************************
* Class Function: setCommand()                                  *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Modifies command                                 *
* Input parameters: command                                     *
* Returns: Nothing                                              *
* Preconditions: command                                        *
* Postconditions: The command has been modified                 *
*****************************************************************/
template <class command, class description>
void Node<command, description>::setCommand(command c) {
    this->c = c;
}

/****************************************************************
* Class Function: setDescription()                              *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Modifies description                             *
* Input parameters: description                                 *
* Returns: Nothing                                              *
* Preconditions: description                                    *
* Postconditions: The description has been modified             *
*****************************************************************/
template <class command, class description>
void Node<command, description>::setDescription(description d) {
    this->d = d;
}

/****************************************************************
* Class Function: setNext()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Modifies next pointer                            *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: The next pointer has been modified            *
*****************************************************************/
template <class command, class description>
void Node<command, description>::setNext(Node<command, description>* pNext) {
    this->pNext = pNext;
}

/****************************************************************
* Class Function: List()                                        *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: A constructor                                    *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: An object has been initialized                *
*****************************************************************/
template <class command, class description>
List<command, description>::List(Node<command, description>* pRoot) {
    this->pRoot = pRoot;
}

/****************************************************************
* Class Function: ~List()                                       *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: A destructor                                     *
* Input parameters: None                                        *
* Returns: Nothing                                              *
* Preconditions: None                                           *
* Postconditions: An object has been destroyed                  *
*****************************************************************/
template <class command, class description>
List<command, description>::~List() {

}

/****************************************************************
* Class Function: getRoot()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Returns root pointer                             *
* Input parameters: None                                        *
* Returns: Node*                                                *
* Preconditions: None                                           *
* Postconditions: Root pointer has been returned                *
*****************************************************************/
template <class command, class description>
Node<command, description>* List<command, description>::getRoot() {
    return pRoot;
}

/****************************************************************
* Class Function: setRoot()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Modifies root pointer                            *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: Root pointer has been modified                *
*****************************************************************/
template <class command, class description>
void List<command, description>::setRoot(Node<command, description>* pRoot) {
    this->pRoot = pRoot;
}

/****************************************************************
* Class Function: insertFront()                                 *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Inserts new node in the front of list            *
* Input parameters: command and description                     *
* Returns: Nothing                                              *
* Preconditions: command and description                        *
* Postconditions: The new node has been inserted at the front   *
*****************************************************************/
template <class command, class description>
void List<command, description>::insertFront(command c, description d) {
    if (pRoot == nullptr)
        pRoot = new Node<command, description>(c, d);

    else {
        Node<command, description>* pMem = new Node<command, description>(c, d);
        pMem->setNext(pRoot);
        pRoot = pMem;
    }
}

/****************************************************************
* Class Function: delNode()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Deletes a node and rearranges list               *
* Input parameters: command                                     *
* Returns: Nothing                                              *
* Preconditions: command                                        *
* Postconditions: A node has been deleted                       *
*****************************************************************/
template <class command, class description>
void List<command, description>::delNode(command c) {
    Node<command, description>* pPrev = nullptr, *pCur = pRoot;

    while (pCur->getCommand() != c) {
        pPrev = pCur;
        pCur = pCur->getNext();
    }

    if (pPrev != nullptr) {
        if (pCur->getNext() != nullptr)
            pPrev->setNext(pCur->getNext());
    }
    else
        pRoot = pCur->getNext();

    delete pCur;
}

/****************************************************************
* Class Function: delList()                                     *
* Date Created: 8/30/2021                                       *
* Date Last Modified: 8/30/2021                                 *
* Description: Deletes the list                                 *
* Input parameters: Node*                                       *
* Returns: Nothing                                              *
* Preconditions: Node*                                          *
* Postconditions: The list has been deleted                     *
*****************************************************************/
template <class command, class description>
void List<command, description>::delList(Node<command, description>* pRoot) {
    if (pRoot != nullptr) {
        delList(pRoot->getNext());
        delete pRoot;
    }
}