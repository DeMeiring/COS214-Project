#include "Engineering.h"

Engineering::Engineering(string RNDName, bool isDept)
{
	this->RnD_Name = RNDName;
	this->isDept = isDept;
}

string Engineering::getRnDName() {
	// TODO - implement Engineering::getRnDName
	return RnD_Name;
}

int Engineering::getCostOfComponent(Engineering* Comp) {
	// TODO - implement Engineering::getCostOfComponent
	throw "Not yet implemented";
}

int Engineering::getTotalCost() {
	// TODO - implement Engineering::getTotalCost
	throw "Not yet implemented";
}

// void Engineering::addDepartment(Engineering* Dept) {
// 	// TODO - implement Engineering::addDepartment
// 	throw "Not yet implemented";
// }

// Engineering_Iterator* Engineering::createIterator() {
// 	// TODO - implement Engineering::createIterator
// 	throw "Not yet implemented";
// }

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