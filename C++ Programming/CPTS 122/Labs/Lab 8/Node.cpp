#include "Node.h"

Node::Node(string newData) {
	data = newData;
	mpLeft = mpRight = nullptr;
}

string Node::getData() {
	return data;
}

void Node::setData(string& newData) {
	data = newData;
}

Node* Node::getLeftPtr() {
	return mpLeft;
}

Node* Node::getRightPtr() {
	return mpRight;
}

void Node::setLeftPtr(Node* ptr) {
	mpLeft = ptr;
}

void Node::setRightPtr(Node* ptr) {
	mpRight = ptr;
}

ostream& operator<< (ostream& lhs, Node& rhs) {
	lhs << rhs.getData() << endl;
	return lhs;
}