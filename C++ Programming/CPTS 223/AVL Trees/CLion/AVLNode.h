/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 223                                                       *
* Programming Assignment: PA 2 - AVL Trees                              *
* Date: 11/01/2021                                                      *
* Description: This program designs an AVL tree                         *
************************************************************************/

#pragma once

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class AVLNode{
public:
    AVLNode(T data){
        this->data = data;
        pLeft = nullptr;
        pRight = nullptr;
        height = 0;
    }

    ~AVLNode(){

    }

    T data;
    AVLNode<T>* pLeft;
    AVLNode<T>* pRight;
    int height;
};