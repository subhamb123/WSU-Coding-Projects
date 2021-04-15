#include "Student.hpp"
#include "Teacher.hpp"

int main() {
	TestPerson test;
	test.testPerson();
	test.testCopyPerson();
	test.testEquals();
	test.testExtraction();
	test.testInsertion();

	Student s;
	s.computeCredits();
	cout << "GPA: " << s.computeGPA() << endl;

	Teacher t;
	t.computeCredits();
	cout << "Average: " << t.computeAverage() << endl;

	return 0;
}