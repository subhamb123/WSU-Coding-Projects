#include "Teacher.hpp"

Teacher::Teacher(int num, int Credits) {
	numCourses = num;
	credits = Credits;
	courses = new Courses[numCourses];

	string classes[] = { "Computer Science", "Math", "Physics", "English", "History", "Accounting" };
	double grades[] = { 4, 3.5, 3, 2, 1, 0 };

	for (int i = 0; i < numCourses; i++) {
		courses[i].name = classes[i];
		courses[i].credits = credits / numCourses;
		courses[i].averageGrade = grades[i];
	}
}

void Teacher::computeCredits() {
	credits = 0;
	for (int i = 0; i < numCourses; i++)
		credits += courses[i].credits;
}

double Teacher::computeAverage() {
	double average = 0;
	for (int i = 0; i < numCourses; i++)
		average += courses[i].averageGrade;

	return average / numCourses;
}