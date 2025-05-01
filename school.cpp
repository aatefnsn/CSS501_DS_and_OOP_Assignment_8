#include "pch.h"
#include "school.h"

school::school() {
	this->superv = nullptr;
	this->setNumberOfInstructors(0);
}

school::school(supervisor * root) {
	this->superv = root;
	this->setNumberOfInstructors(0);
}

void school::setRoot(supervisor * root) {
	this->superv = root;	
}

supervisor * school::getRoot() {
	return this->superv;
}

int school::getNumberOfInstructors() {
	return this->NumberOfInstructors;
}

int school::getNumberOfStudents() {
	return this->NumberOfStudents;
}

void school::setNumberOfStudents(int NumberOfStudents) {
	if (NumberOfStudents >= 0)
		this->NumberOfStudents = NumberOfStudents;
}

void school::setNumberOfInstructors(int NumberOfInstructors) {
	if (NumberOfInstructors >= 0)
		this->NumberOfInstructors = NumberOfInstructors;
}

void school::Add(instructor &p) {
	if (&p != nullptr && !find(p)) {
		this->superv->instructor_list.push_back(p);
		this->setNumberOfInstructors(NumberOfInstructors + 1);
	}
}

void school::Add(student &s) {
	int min = this->findMinStudents();
	int max = this->findMaxStudents();
	if (min >= 5 && max < 8) {
		this->findInstructorWithMaxStudents()->getStudentList().push_back(s);
	}
	else {
		
		this->findInstructorWithMinStudents()->getStudentList().push_back(s);
	}
	this->setNumberOfStudents(NumberOfStudents + 1);
}

void school::Add(student &s, instructor &i) {
	if (find(i)) {
		for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
			instructor &temp = *it;
			if (temp.getName() == i.getName()) {
				temp.getStudentList().push_back(s);
			}
		}
	}
	else {
		cout << "Error: The instructor has been removed from the Ski School" << endl;
	}
}

void school::Remove(student &s) {
	if (findStudent(s)) {
		for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
			instructor tt = *it;
			vector<student> toSearch = tt.getStudentList();
			if (!toSearch.empty()) {
				int index = 0;
				for (auto it2 = toSearch.begin(); it2 != toSearch.end(); it2++) {
					student ss = *it2;
					if (ss.getName() == s.getName()) {
						(*it).getStudentList().erase((*it).getStudentList().begin() + index);
						break;
					}
						index++;
				}
			}
		}
		this->setNumberOfStudents(NumberOfStudents - 1);
	}
}

void school::Remove(instructor &p) {
	vector<student> * vecOrphanedStudents = new vector<student>();
	if (find(p)) {	
		int index = findIndex(p);
		instructor * tobeRemoved = this->findInstructor(p);
		cout << "index is " << index << endl; 
		vecOrphanedStudents = &tobeRemoved->getStudentList();
		cout << vecOrphanedStudents->front().getName() << endl;

		for (auto it = vecOrphanedStudents->begin(); it != vecOrphanedStudents->end(); it++) {
			student s = (*it) ;
			this->Add(*it);
		}

		this->superv->instructor_list.erase(this->superv->instructor_list.begin() + index);
		NumberOfInstructors = NumberOfInstructors - 1;
	}
}

bool school::findInstructorByName(string str) {
	bool found = false;
	instructor * temp = &(this->superv->instructor_list.front());
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		int index = 0;
		temp = &*it;
		string itiname = temp->getName();
		if (itiname == str) {
			found = true;
			cout << "Instructor found at index " << index << endl; 
			return true;
		}
	}
	if (!found)
		cout << "Instructor was not found " << endl;
	return found;
}

bool school::findInstructorByStudentName(string str) {
	bool found = false;
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		instructor tt = *it;
		vector<student> toSearch = tt.getStudentList();
		if (!toSearch.empty()) {
			for (auto it2 = toSearch.begin(); it2 != toSearch.end(); it2++) {
				student ss = *it2;
				if (ss.getName() == str) {
					found = true;
					cout << "The instructor for student " << str << " is Mr./Mrs. " << tt.getName() << endl;
					return true;
				}
			}
		}
	}
	if (!found)
		cout << "No instructor found for that student" << endl;
	return found;
}

instructor * school::findInstructor(instructor &p) {
	instructor * temp = &(this->superv->instructor_list.front());
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		 temp = &*it;
		string itiname = temp->getName();
		if (itiname == p.getName()) {
			return temp;
		}
	}
	return temp;
}

bool school::find(instructor &p) {
	bool found = false;
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		instructor temp = *it;
		string itiname = temp.getName();
		if (itiname == p.getName()) {
			found = true;
			return true;
		}
	}
	return found;
}

bool school::findStudent(student &p) {
	bool found = false;
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		instructor tt = *it;
		vector<student> toSearch = tt.getStudentList();
		if (!toSearch.empty()) {
			for (auto it2 = toSearch.begin(); it2 != toSearch.end(); it2++) {
				student ss = *it2;
				if (ss.getName() == p.getName()) {
					found = true;
					return true;
				}
			}
		}
	}
	return found;
}

int school::findIndex(instructor &p) {
	int index = 0;
	if (!find(p)) {
		return -1;
	}
	else {
		for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
			instructor temp = *it;
			string itiname = temp.getName();
			if (itiname == p.getName()) {
				return index;
			}
			index++;
		}
	}
	return index;
}

instructor * school::findInstructorWithMinStudents() {
	instructor * temp = &(this->superv->instructor_list.front());
	int min = temp->getClassSize();


	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		instructor tt = *it;
		if (tt.getClassSize() < min) {
			temp = &*it;
			min = tt.getClassSize();
		}
	}
	return temp;
}

instructor * school::findInstructorWithMaxStudents() {
	instructor * temp = &(this->superv->instructor_list.front());
	int max = temp->getClassSize();

	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		instructor tt = *it;
		if (tt.getClassSize() > max) {
			temp = &*it;
			max = tt.getClassSize();
		}
	}
	return temp;
}


int school::findMinStudents() {
	int min = this->superv->instructor_list.front().getClassSize();
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		instructor tt = *it;
		if (tt.getClassSize() < min) {
			min = tt.getClassSize();
		}
	}
	return min;
}

int school::findMaxStudents() {
	int max = this->superv->instructor_list.front().getClassSize();
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {
		instructor tt = *it;
		if (tt.getClassSize() > max) {
			max = tt.getClassSize();
		}
	}
	return max;
}

void school::printSchool() {
	this->superv->printSupervisor();
	for (auto it = this->superv->instructor_list.begin(); it != this->superv->instructor_list.end(); it++) {

		instructor tt = *it;
		tt.printInstructor();
		vector<student> toprint = tt.getStudentList();
		if (!toprint.empty()) {
			for (auto it2 = toprint.begin(); it2 != toprint.end(); it2++) {
				student ss = *it2;
				ss.printStudent();
			}
		}
	}
}