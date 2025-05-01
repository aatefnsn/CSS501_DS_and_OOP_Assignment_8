#include "pch.h"
#include "person.h"

person::person() {
	this->setName("");
}
person::person(string name) {
	this->setName(name);
}

string person::getName() const {
	return this->name; 
}

void person::setName(string name) {
	if (&name == nullptr) {
		this->name = "";
	}
	else {
		this->name = name;
	}
}

void person::printPerson() {
	cout << "Person\n name: " << this->getName() << endl; 
}
