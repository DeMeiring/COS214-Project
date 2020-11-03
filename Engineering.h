#ifndef ENGINEERING_H
#define ENGINEERING_H

class Engineering {

private:
	string RnD_Name;
	boolean isDept;

public:
	string getRnDName();

	int getCostOfComponent(Engineering* Comp);

	int getTotalCost();

	void addDepartment(Engineering* Dept);

	Engineering_Iterator* createIterator();

	boolean getIsDept();

	void setIsDept(boolean isDept);
};

#endif
