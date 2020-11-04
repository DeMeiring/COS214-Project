#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <vector>
#include "Engineering.h"

using namespace std;

class Department : Engineering {

private:
	vector<Engineering*> RnD;
	vector<string> ListOfComponents;

public:
	Department();

	void addDepartment(Engineering* Dept);

	bool levelComponent(Engineering* Component, bool upgrade);

	vector<string> getComponentList();
};

#endif
