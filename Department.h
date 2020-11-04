#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Engineering.h"
#include <string>
#include <vector>

class Department: public Engineering
{
private:
	vector<Engineering*> RnD;
	vector<string> ListOfComponents;

public:
	Department(string, bool);

	void addDepartment(Engineering* Dept);

	bool levelComponent(Engineering* Component, bool upgrade);

	vector<string> getComponentList();

	virtual ~Department();
};

#endif
