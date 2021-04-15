#include "Student.hpp"

Student::Student(int num, int Credits) {
	numCourses = num;
	credits = Credits;
	courses = new Course[numCourses];

	string classes[] = { "Computer Science", "Math", "Physics", "English", "History", "Accounting" };
	double grades[] = { 4, 3.5, 3, 2, 1, 0 };

	for (int i = 0; i < numCourses; i++) {
		courses[i].name = classes[i];
		courses[i].credits = credits / numCourses;
		courses[i].grade = grades[i];
	}
}

void Student::computeCredits() {
	credits = 0;
	for (int i = 0; i < numCourses; i++)
		credits += courses[i].credits;
}

double Student::computeGPA() {
	double GPA = 0;
	for (int i = 0; i < numCourses; i++)
		GPA += courses[i].grade;

	return GPA / numCourses;
}