#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node {
public:
	Node(string newData = "");
	string getData();
	Node* getLeftPtr();
	Node* getRightPtr();
	void setData(string& data);
	void setLeftPtr(Node* ptr);
	void setRightPtr(Node* ptr);

private:
	string data;
	Node* mpLeft;
	Node* mpRight;
};

ostream& operator<< (ostream& lhs, Node& rhs);