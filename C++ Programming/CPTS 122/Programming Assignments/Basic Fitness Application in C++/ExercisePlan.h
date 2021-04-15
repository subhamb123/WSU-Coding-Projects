/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 4 - Basic Fitness Application in C++       *
* Date: 2/26/2021                                                       *
* Description: This program is a basic fitness application.             *
************************************************************************/

#pragma once

#include "header.h"

class ExercisePlan {
public:
	ExercisePlan();
	ExercisePlan(int stepGoal, string name, string date);
	ExercisePlan(ExercisePlan& copy);
	~ExercisePlan();
	int getStepGoal() const;
	string getName() const;
	string getDate() const;
	void setStepGoal(int goal);
	void setName(string name);
	void setDate(string date);
	void editGoal(int goal);

private:
	int stepGoal;
	string planName;
	string date;
};

ostream& operator<< (ostream& lhs, ExercisePlan& rhs);
fstream& operator<< (fstream& lhs, ExercisePlan& rhs);
fstream& operator>> (fstream& lhs, ExercisePlan& rhs);