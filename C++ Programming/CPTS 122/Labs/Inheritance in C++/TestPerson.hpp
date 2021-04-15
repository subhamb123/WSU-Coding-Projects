#pragma once

#include "Person.hpp";

class TestPerson : public Person {
public:
	void testPerson();
	void testCopyPerson();
	void testEquals();
	void testExtraction();
	void testInsertion();
	void copyHelper(Person p);
};