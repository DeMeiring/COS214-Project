#include "Engineering.h"

Engineering::~Engineering() {}

Engineering::Engineering(string RNDName, bool isDept)
{
	this->RnD_Name = RNDName;
	this->isDept = isDept;
}

string Engineering::getRnDName() {
	// TODO - implement Engineering::getRnDName
	return RnD_Name;
}

int Engineering::getCost()
{
	return Cost;
}

int Engineering::getLevel()
{
	return level;
}

Statistics* Engineering::getStats()
{
    if(stats==nullptr)
        return new Statistics(true);
	return stats;
}

// int Engineering::getTotalCost() {
	
// }
// void Engineering::addDepartment(Engineering* Dept) {
// 	// TODO - implement Engineering::addDepartment
// 	throw "Not yet implemented";
// }

Engineering_Iterator* Engineering::createIterator(Engineering* Dept) {
	Engineering_Iterator* iterator = new Engineering_Iterator(Dept);
	return iterator;
}

vector<Engineering*> Engineering::getRnD()
{
	return RnD;
}

bool Engineering::getIsDept() {
	return this->isDept;
}

void Engineering::setIsDept(bool isDept) {
	this->isDept = isDept;
}

int Engineering::getCompIndex()
{
	return compIndex;
}

void Engineering::setCompIndex(int index)
{
	compIndex = index;
}

int Engineering::getDeptIndex()
{
	return deptIndex;
}

void Engineering::setDeptIndex(int index)
{
	deptIndex = index;
}

