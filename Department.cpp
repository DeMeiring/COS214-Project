#include "Department.h"

using namespace std;

Department::Department(string RNDName, bool isDept): Engineering(RNDName, isDept) {
	// TODO - implement Department::Department

	//Add a child to the composite(Engineering)
	
	//Add a department called (parameter::Engineering* aerodynamics)
	//create a new department with engineering name aerodynamics and isDept = true;
	//Department.h holds the vector of Engineering objects = {Aero, Chassis}
	// Aero,

}

void Department::addDepartment(Engineering* Dept) {//pushes Engineering Objects to the Engineering vector
	// TODO - implement Department::addDepartment
	RnD.push_back(Dept);
}

bool Department::levelComponent(Engineering* Component, bool upgrade) { //bool indicates increase or decrease
	// TODO - implement Department::levelComponent 
	throw "Not yet implemented";
}

vector<string> Department::getComponentList(Engineering* Dept) {
	// TODO - implement Department::getComponentList
	Engineering_Iterator *iterator = new Engineering_Iterator(Dept);
	vector<string> componentList;
	for (int i = 0; i < 3; i++)
	{
		componentList.push_back(iterator->CurrentComp()->getRnDName());
		iterator->NextComp();
	}
	return componentList;
}

Department::~Department()
{}
