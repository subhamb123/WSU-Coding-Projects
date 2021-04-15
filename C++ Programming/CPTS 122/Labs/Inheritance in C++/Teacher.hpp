#pragma once

#include "TestPerson.hpp";

typedef struct courses {
	string name;
	int credits;
	double averageGrade;
} Courses;

class Teacher : public Person {
public:
	Teacher(int num = 6, int Credits = 18);
	void computeCredits();
	double computeAverage();
private:
	Courses* courses;
	int numCourses;
	int credits;
};