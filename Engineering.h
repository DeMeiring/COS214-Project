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
	int getCompIndex();//eng

	int getDeptIndex();

	void setCompIndex(int index);

	void setDeptIndex(int index);

	Engineering();

	virtual ~Engineering();

	Engineering(string, bool);

	string getRnDName();//engineering

	virtual int getCost();//comp

	virtual int getLevel();//comp

	virtual Statistics* getStats();//comp

	virtual vector<string> getComponentList(Engineering *Dept) = 0;

	vector<Engineering*> getRnD();//dept

	virtual void addDepartment(Engineering* Dept) = 0;
	
	Engineering_Iterator* createIterator(Engineering *Dept);

//iterator
	bool getIsDept();//isself

	void setIsDept(bool isDept);

	virtual bool ChangeLevel(int level)=0;//comp
};

#endif
