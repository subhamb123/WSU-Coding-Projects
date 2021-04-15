/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 5 - Grocery Store Simulation               *
* Date: 3/11/2021                                                       *
* Description: This program simulates grocery store lanes.              *
************************************************************************/

//Guard Code
#pragma once

//Header Files
#include "header.hpp"

//Classes
class Data {
public:
    Data(int number = 0, int service = 0, int total = 0);
    ~Data();
    void setNumber(int number);
    void setService(int service);
    void setTotal(int total);
    int getNumber() const;
    int getService() const;
    int getTotal() const;
private:
    int customerNumber;
    int serviceTime;
    int totalTime;
};

class QueueNode {
public:
    QueueNode(const Data* customer = nullptr, QueueNode* pNext = nullptr);
    ~QueueNode();
    void setNextPtr(QueueNode* const pNext);
    QueueNode* getNextPtr() const;
    Data* getData() const;
private:
    Data* pData;
    QueueNode* pNext;
};