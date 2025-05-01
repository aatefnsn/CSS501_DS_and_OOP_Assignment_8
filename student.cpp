#include "pch.h"
#include "student.h"

student::student(): person() {

}

string student::getName() {
	return this->person::getName();
}

student::student(string name): person (name) {
	
}

void student::printStudent() {
	cout << "  - student name: " << this->getName() << endl;
}
