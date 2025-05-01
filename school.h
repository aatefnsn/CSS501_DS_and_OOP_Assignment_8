#pragma once
#include "supervisor.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class school {

private:
	supervisor * superv;
	int NumberOfInstructors=0;
	int NumberOfStudents=0;
	instructor * findInstructorWithMinStudents();
	instructor * findInstructorWithMaxStudents();
public:
	school();
	school(supervisor * root);
	void setRoot(supervisor * root);
	supervisor * getRoot();
	int getNumberOfInstructors();
	int getNumberOfStudents();
	void setNumberOfStudents(int NumberOfStudents);
	void setNumberOfInstructors(int NumberOfInstructors);
	void Add(instructor &i);
	void Add(student &s);
	void Add(student &s, instructor &i);
	void Remove(student &s);
	void Remove(instructor &i);
		
	bool find(instructor &p);
	bool findStudent(student &p);

	bool findInstructorByName(string str);
	bool findInstructorByStudentName(string str);

	instructor * findInstructor(instructor &p);
	int findIndex(instructor &p);
	int findMinStudents();
	int findMaxStudents();
	void printSchool();
};