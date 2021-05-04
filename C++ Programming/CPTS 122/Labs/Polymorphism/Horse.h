#pragma once

#include "Mammal.h"

class Horse : public Mammal {
public:
	Horse(void) {
		cout << "Horse constructor..." << endl;
	}
	~Horse(void) {
		cout << "Horse destructor..." << endl;
	}
	void Move() const {
		cout << "Horse moves a step!" << endl;
	}
	void Speak() const {
		cout << "What does a horse speak? Horseilian!" << endl;
	}
};