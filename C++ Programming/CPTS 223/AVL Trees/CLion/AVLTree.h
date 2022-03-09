/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 223                                                       *
* Programming Assignment: PA 2 - AVL Trees                              *
* Date: 11/01/2021                                                      *
* Description: This program designs an AVL tree                         *
************************************************************************/

#pragma once

#include "AVLNode.h"

template <class T>
class AVLTree{
public:
    AVLTree(){
        pRoot = nullptr;
    }

    ~AVLTree(){
        deleteTree(pRoot); //This deletes the tree when it goes out of scope in main function
    }

    int getHeight(AVLNode<T>* node){
        return node == nullptr ? -1 : node->height;
    }

    void insert(T value, AVLNode<T>*& pCur){
        if(pCur == nullptr)
            pCur = new AVLNode<T>(value);

        else if(value > pCur->data)
            insert(value, pCur->pRight);

        else if(value < pCur->data)
            insert(value, pCur->pLeft);

        balance(pCur); //Checks if balancing is required after insertion of new node
    }

    void balance(AVLNode<T>*& node){
        if(node == nullptr)
            return;

        if(getHeight(node->pLeft) - getHeight(node->pRight) > 1){
            if(getHeight(node->pLeft->pLeft) >= getHeight(node->pLeft->pRight))
                node = rightRotate(node);
            else
                node = doubleRightRotate(node);
        }

        if(getHeight(node->pRight) - getHeight(node->pLeft) > 1){
            if(getHeight(node->pRight->pRight) >= getHeight(node->pRight->pLeft))
                node = leftRotate(node);
            else
                node = doubleLeftRotate(node);
        }

        node->height = max(getHeight(node->pLeft), getHeight(node->pRight)) + 1;
    }

    int max(int a, int b){
        return a > b ? a : b;
    }

    AVLNode<T>* leftRotate(AVLNode<T>*& node1){
        AVLNode<T>* node2 = node1->pRight;
        node1->pRight = node2->pLeft;
        node2->pLeft = node1;
        node1->height = max(getHeight(node1->pRight), getHeight(node1->pLeft)) + 1;
        node2->height = max(getHeight(node2->pRight), node1->height) + 1;
        return node2;
    }

    AVLNode<T>* rightRotate(AVLNode<T>*& node1){
        AVLNode<T>* node2 = node1->pLeft;
        node1->pLeft = node2->pRight;
        node2->pRight = node1;
        node1->height = max(getHeight(node1->pLeft), getHeight(node1->pRight)) + 1;
        node2->height = max(getHeight(node2->pLeft), node1->height) + 1;
        return node2;
    }

    AVLNode<T>* doubleLeftRotate(AVLNode<T>*& node){
        node->pRight = rightRotate(node->pRight);
        node = leftRotate(node);
        return node;
    }

    AVLNode<T>* doubleRightRotate(AVLNode<T>*& node){
        node->pLeft = leftRotate(node->pLeft);
        node = rightRotate(node);
        return node;
    }

    bool contains(T value) {
        AVLNode<T>* node = pRoot;
        while(node != nullptr){
            if(node->data == value)
                return true;

            if(node->data > value)
                node = node->pLeft;

            else
                node = node->pRight;
        }

        return false;
    }

    bool validate(AVLNode<T>* pCur){
        int lHeight;
        int rHeight;

        if (pCur == nullptr)
            return 1;

        lHeight = getHeight(pCur->pLeft);
        rHeight = getHeight(pCur->pRight);

        //Checks if all heights are 1 or less
        if (abs(lHeight - rHeight) <= 1 && validate(pCur->pLeft) && validate(pCur->pRight))
            return 1;

        return 0;
    }

    //Deletes the nodes using postorder
    void deleteTree(AVLNode<T>* pCur){
        if(pCur == nullptr){
            return;
        }

        deleteTree(pCur->pLeft);
        deleteTree(pCur->pRight);
        delete pCur;
    }

    AVLNode<T>* pRoot;
};