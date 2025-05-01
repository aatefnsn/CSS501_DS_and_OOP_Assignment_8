#pragma once
#include <vector>
#include "person.h"
#include "student.h"
#include "instructor.h"

class supervisor : public person {
private:

public:
	vector<instructor> instructor_list;
	supervisor();
	supervisor(string name);
	string getName() const;
	void printSupervisor();
	void Add(instructor &p);
	friend ostream& operator<<(ostream &os, const supervisor &p) {
		os << "Supervisor\n name: " << p.getName() << endl;
		return os;
	}
};
