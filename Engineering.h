#ifndef ENGINEERING_H
#define ENGINEERING_H

#include <string>
#include <vector>

#include "Engineering_Iterator.h"
#include "Statistics.h"
using namespace std;

class Engineering {
	friend class Department;

private:
	vector<Engineering*> RnD;
	string RnD_Name;
	bool isDept;
	int deptIndex;
	int compIndex;
	
	
protected:
	int Cost;
	int level;
	Statistics* stats;

public:
	int getCompIndex();

	int getDeptIndex();

	void setCompIndex(int index);

	void setDeptIndex(int index);

	Engineering();

	Engineering(string, bool);

	string getRnDName();

	virtual int getCost();

	virtual int getLevel();

	virtual Statistics* getStats();

	virtual vector<string> getComponentList(Engineering *Dept) = 0;

	virtual int getCostOfComponent(Engineering* Comp);

	int getTotalCost();

	vector<Engineering*> getRnD();

	virtual void addDepartment(Engineering* Dept) = 0;
	
	Engineering_Iterator* createIterator(Engineering *Dept);

	bool getIsDept();

	void setIsDept(bool isDept);

	virtual bool ChangeLevel(int level)=0;
};

#endif
