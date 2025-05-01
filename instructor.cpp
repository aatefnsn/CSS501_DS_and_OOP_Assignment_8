#include "pch.h"
#include "instructor.h"

instructor::instructor():person() {
	vector<student> * student_list = new vector<student>();
	numberOfStudents = 0;
}
instructor::instructor(string name): person(name) {
	vector<student> * student_list = new vector<student>();
	this->setNumberOfStudents(0);
}

instructor::instructor(string name, int number): person(name) {
		this->setNumberOfStudents(number);
}

void instructor::printInstructor() {
	cout << "Instructor name: " << this->getName() << " - Number of Students: " << this->getNumberOfStudents() << endl;
}

void instructor::setNumberOfStudents(int number) {
	if (number >= 0)
		this->numberOfStudents = number;
	else
		this->numberOfStudents = 0;
}

int instructor::getNumberOfStudents() {
	return this->getClassSize();
}

string instructor::getName() {
	return this->person::getName();
}

vector<student>& instructor::getStudentList() {
	return this->student_list;
}

int instructor::getClassSize() {
	return this->student_list.size();
}
