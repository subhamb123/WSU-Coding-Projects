#pragma once

#include "TestPerson.hpp";

typedef struct course {
	string name;
	int credits;
	double grade;
} Course;

class Student : public Person {
public:
	Student(int num = 6, int Credits = 18);
	void computeCredits();
	double computeGPA();
private:
	Course* courses;
	int numCourses;
	int credits;
};