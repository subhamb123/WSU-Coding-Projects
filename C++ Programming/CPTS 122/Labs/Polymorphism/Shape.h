#pragma once

#include "Mammal.h"

class Shape {
public:
	Shape() {

	}
	~Shape() {

	}
	virtual Shape* copy() = 0;
};

class Rectangle : public Shape {
public:
	Rectangle(double length, double width) {

	}
	~Rectangle() {

	}
};

class Square : public Rectangle {
public:
	Square(double length) : Rectangle(length, 0) {

	}
	~Square() {

	}
	Shape* copy() {
		return new Square(*this);
	}
};