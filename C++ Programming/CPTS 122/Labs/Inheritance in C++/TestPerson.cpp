#include "TestPerson.hpp"

void TestPerson::testPerson() {
	Person p("lol", 5, 'M', 60);
	p.setAge(10);
	if (p.getName() == "lol" && p.getAge() == 10)
		cout << "Test case passed" << endl;
	else
		cout << "Test case failed" << endl;
}

void TestPerson::testCopyPerson() {
	Person p("lol", 5, 'M', 60);
	copyHelper(p);
}

void TestPerson::testEquals() {
	Person p("lol", 5, 'M', 60);
	Person p2 = p;
	if (p2.getName() == "lol" && p2.getAge() == 5)
		cout << "Test case passed" << endl;
	else
		cout << "Test case failed" << endl;
}

void TestPerson::testExtraction() {
	Person p("lol", 5, 'M', 60);
	cout << p;
	cout << endl << "Test case passed" << endl;
}

void TestPerson::testInsertion() {
	Person p;
	cin >> p;
	cout << "Test case passed" << endl;
}

void TestPerson::copyHelper(Person p) {
	if (p.getName() == "lol" && p.getAge() == 5)
		cout << "Test case passed" << endl;
	else
		cout << "Test case failed" << endl;
}