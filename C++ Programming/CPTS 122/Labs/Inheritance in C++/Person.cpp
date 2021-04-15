#include "Person.hpp"

Person::Person(string Name, int Age, char Gender, int Height) {
	name = Name;
	age = Age;
	gender = Gender;
	height = Height;
}

Person::~Person() {

}

Person::Person(const Person& copy) {
	name = copy.getName();
	age = copy.getAge();
	gender = copy.getGender();
	height = copy.getHeight();
}

Person& Person::operator= (const Person& rhs) {
	if (this != &rhs) {
		name = rhs.getName();
		age = rhs.getAge();
		gender = rhs.getGender();
		height = rhs.getHeight();
	}

	return *this;
}

string Person::getName() const {
	return name;
}

int Person::getAge() const {
	return age;
}

char Person::getGender() const {
	return gender;
}

int Person::getHeight() const {
	return height;
}

void Person::setName(string Name) {
	name = Name;
}

void Person::setAge(int Age) {
	age = Age;
}

void Person::setGender(char Gender) {
	gender = Gender;
}

void Person::setHeight(int Height) {
	height = Height;
}

ostream& operator<< (ostream& lhs, Person& rhs) {
	lhs << "Name: " << rhs.getName() << ", age: " << rhs.getAge() << ", gender: " << rhs.getGender() << ", height: " << rhs.getHeight();
	return lhs;
}

istream& operator>> (istream& lhs, Person& rhs) {
	string temp = "";
	int temp2 = 0;
	char temp3 = '\0';

	cout << "Enter name" << endl;
	lhs >> temp;
	rhs.setName(temp);

	cout << "Enter age" << endl;
	lhs >> temp2;
	rhs.setAge(temp2);

	cout << "Enter gender" << endl;
	lhs >> temp3;
	rhs.setGender(temp3);

	cout << "Enter height" << endl;
	lhs >> temp2;
	rhs.setHeight(temp2);

	return lhs;
}