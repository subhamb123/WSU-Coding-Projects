/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 7 - Attendance Tracker w/ class Templates  *
* Date: 3/30/2021                                                       *
* Description: This program manages attendance for a course.            *
************************************************************************/

//Guard Code
#pragma once

//Header Files
#include "header.hpp"

//Classes
class Stack {
public:
	Stack();
	~Stack();
	Stack& operator= (const Stack& rhs);
	int getSize() const;
	string* getArray() const;
	void push(string newItem);
	void pop(string& poppedItem);
	void peek(string& item);
	bool isEmpty();
private:
	int mSize;
	string* mTop;
};

class Data {
public:
	Data();
	~Data();
	void setRecNum(int n);
	void setID(int n);
	void setName(string s);
	void setEmail(string s);
	void setUnits(string s);
	void setMajor(string s);
	void setLevel(string s);
	void setAbsences(int n);
	void setAbsenceDates(Stack& s);
	void incrementAbsences();
	void decrementAbsences();
	int getRecNum() const;
	int getID() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getMajor() const;
	string getLevel() const;
	int getAbsences() const;
	Stack& getAbsenceDates();
private:
	int recNum;
	int ID;
	string name;
	string email;
	string units;
	string major;
	string level;
	int absences;
	Stack absenceDates;
};