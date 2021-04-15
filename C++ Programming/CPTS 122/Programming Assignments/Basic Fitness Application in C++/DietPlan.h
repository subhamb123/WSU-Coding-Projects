/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 4 - Basic Fitness Application in C++       *
* Date: 2/26/2021                                                       *
* Description: This program is a basic fitness application.             *
************************************************************************/

#pragma once

#include "header.h"

class DietPlan {
public:
	DietPlan();
	DietPlan(int calorieGoal, string name, string date);
	DietPlan(DietPlan& copy);
	~DietPlan();
	int getCalorieGoal() const;
	string getName() const;
	string getDate() const;
	void setCalorieGoal(int goal);
	void setName(string name);
	void setDate(string date);
	void editGoal(int goal);

private:
	int calorieGoal;
	string name;
	string date;
};

ostream& operator<< (ostream& lhs, DietPlan& rhs);
fstream& operator<< (fstream& lhs, DietPlan& rhs);
fstream& operator>> (fstream& lhs, DietPlan& rhs);