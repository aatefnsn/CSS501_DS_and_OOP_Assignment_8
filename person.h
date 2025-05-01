#pragma once
#include <string>
#include <iostream>
using namespace std;

class person {
private:
	string name;
public: 
	person();
	person(string name); 
	string getName() const;
	void setName( string name);
	virtual void printPerson(); 
	friend ostream& operator<<(ostream &os, const person &p) {
		os << "Person\n name: " << p.name << endl;
		return os;
	}
};