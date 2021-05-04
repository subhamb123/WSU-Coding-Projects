#pragma once

#include "Mammal.h"

class GuineaPig : public Mammal {
public:
	GuineaPig(void) {
		cout << "Guinea Pig constructor..." << endl;
	}
	~GuineaPig(void) {
		cout << "Guinea Pig destructor..." << endl;
	}
	void Move() const {
		cout << "Guinea Pig moves a step!" << endl;
	}
	void Speak() const {
		cout << "What does a guinea pig speak? Guineapigilian!" << endl;
	}
};