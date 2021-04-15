#pragma once

#include "header.hpp"

class Person {
public:
	Person(string Name = "", int Age = 0, char Gender = '\0', int Height = 0);
	~Person();
	Person(const Person& copy);
	Person& operator= (const Person& rhs);
	string getName() const;
	int getAge() const;
	char getGender() const;
	int getHeight() const;
	void setName(string Name);
	void setAge(int Age);
	void setGender(char Gender);
	void setHeight(int Height);
private:
	string name;
	int age;
	char gender;
	int height;
};

ostream& operator<< (ostream& lhs, Person& rhs);
istream& operator>> (istream& lhs, Person& rhs);