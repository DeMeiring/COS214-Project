#ifndef ENGINEERING_H
#define ENGINEERING_H

#include <string>


using namespace std;

class Engineering {

private:
	string RnD_Name;
	bool isDept;

public:

	Engineering(){};

	Engineering(string, bool);

	string getRnDName();

	virtual int getCostOfComponent(Engineering* Comp);

	int getTotalCost();

	virtual void addDepartment(Engineering* Dept) = 0;

	// Engineering_Iterator* createIterator();

	bool getIsDept();

	void setIsDept(bool isDept);
};

#endif
