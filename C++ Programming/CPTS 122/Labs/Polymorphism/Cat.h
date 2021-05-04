#pragma once

#include "Mammal.h"

class Cat : public Mammal {
public:
	Cat(void) {
		cout << "Cat constructor..." << endl;
	}
	~Cat(void) {
		cout << "Cat destructor..." << endl;
	}
	void Move() const {
		cout << "Cat moves a step!" << endl;
	}
	void Speak() const {
		cout << "What does a cat speak? Catilian!" << endl;
	}
};