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
#include "header.hpp"

//Classes
class Node {
public:
    Node(string data = "");
    virtual ~Node();
    void setData(string data);
    void setLeft(Node* pLeft);
    void setRight(Node* pRight);
    string getData() const;
    Node*& getLeft();
    Node*& getRight();
    virtual void printData() = 0;
protected:
    string mData;
    Node* mpLeft;
    Node* mpRight;
};