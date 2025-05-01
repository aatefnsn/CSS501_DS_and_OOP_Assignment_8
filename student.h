#pragma once
#include "person.h"

class student : private person {
public: 
	student();
	student(string name);
	void printStudent();
	string getName();
};