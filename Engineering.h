#ifndef ENGINEERING_H
#define ENGINEERING_H

#include <string>
#include "Engineering_Iterator.h"

using namespace std;

class Engineering {

private:
	string RnD_Name;
	bool isDept;

public:
	string getRnDName();

	int getCostOfComponent(Engineering* Comp);

	int getTotalCost();

	void addDepartment(Engineering* Dept);

	Engineering_Iterator* createIterator();

	bool getIsDept();

	void setIsDept(bool isDept);
};

#endif
