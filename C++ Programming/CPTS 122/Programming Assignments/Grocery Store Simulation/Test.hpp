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
#include "Queue.hpp"

//Classes
class Test {
public:
	void testEnqueueEmpty();
	void testEnqueueOneNode();
	void testDequeueOneNode();
	void testDequeueTwoNodes();
	void dayRun();
};