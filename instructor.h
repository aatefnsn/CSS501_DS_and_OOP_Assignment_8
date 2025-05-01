#pragma once
#include "node.h"
#include "person.h"
#include "student.h"


class instructor : private person {
private: 
	int numberOfStudents=0; 
public:
	vector<student> student_list;
	instructor();
	instructor(string name, int numberOfStudents);
	instructor(string name);
	void printInstructor(); 
	void setNumberOfStudents(int numberOfStudents);
	int getNumberOfStudents(); 
	void Add(student &p);
	void Remove(student &p);
	int getClassSize();
	string getName();
	vector<student>& getStudentList();
};

