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
#include "BST.hpp"

//Classes
class DataAnalysis {
public:
	void runAnalysis();
private:
	void openFile();
	void lineProcess(int& units, string& type, string& transaction);
	void importFile();
	void insertInTrees(string transaction, int units, string type);
	void display();
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
};