#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Engineering.h"
#include "Engineering_Iterator.h"
#include <string>
#include <vector>

using namespace std;

class Department: public Engineering
{

private:
	
	vector<string> ListOfComponents;

public:
	Department(string, bool);

	void setCost(int cost);

	void addDepartment(Engineering* Dept);

	bool levelComponent(Engineering* Component, bool upgrade);

	vector<string> getComponentList();

	virtual ~Department();
};

#endif
