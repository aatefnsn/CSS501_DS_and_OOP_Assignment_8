#include "pch.h"
#include"supervisor.h"

supervisor::supervisor(): person() {
	vector<instructor> * instructor_list = new vector<instructor>();
}

supervisor::supervisor(string name): person(name) {
	vector<instructor> * instructor_list = new vector<instructor>();
}

void supervisor::printSupervisor() {
	cout << "supervisor\n name: " << this->getName() << endl;
}

string supervisor::getName() const {
	return person::getName();
}

