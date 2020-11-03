#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class Department : Engineering {

private:
	vector<Engineering*> RnD;
	vector<string> ListOfComponents;

public:
	Department();

	void addDepartment(Engineering* Dept);

	boolean levelComponent(Engineering* Component, boolean upgrade);

	vector<string> getComponentList();
};

#endif
