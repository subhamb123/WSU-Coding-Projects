/************************************************************************
* Programmer: Subham Behera                                             *
* Class: CptS 122; Lab Section 13                                       *
* Programming Assignment: PA 4 - Basic Fitness Application in C++       *
* Date: 2/26/2021                                                       *
* Description: This program is a basic fitness application.             *
************************************************************************/

#pragma once

#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper {
public:
	FitnessAppWrapper();
	void runApp();
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);
	void displayDailyPlan(DietPlan& plan);
	void displayWeeklyPlan(DietPlan weeklyPlan[]);
	void displayDailyPlan(ExercisePlan& plan);
	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);
	void storeDailyPlan(fstream& fileStream, DietPlan& plan);
	void storeWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void storeDailyPlan(fstream& fileStream, ExercisePlan& plan);
	void storeWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);
	int displayMenu();

private:
	DietPlan dietWeekly[7];
	ExercisePlan exerciseWeekly[7];
	fstream dietStream;
	fstream exerciseStream;
};