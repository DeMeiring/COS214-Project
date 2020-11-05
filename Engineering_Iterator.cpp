#include "Engineering_Iterator.h"
#include "Department.h"
Engineering_Iterator::Engineering_Iterator(Engineering *first){
	this->First = first;
	this->CurrDept = first;
	CurrDept->setDeptIndex(0);
}
Engineering *Engineering_Iterator::NextDept()
{
	while (CurrDept->getRnD()[CurrDept->getDeptIndex()] != NULL)
	{
		CurrDept->setDeptIndex(CurrDept->getDeptIndex() + 1);
	}
	if(CurrDept->getRnD()[CurrDept->getDeptIndex() - 1]->getIsDept() == true)
	CurrDept = CurrDept->getRnD()[CurrDept->getDeptIndex() - 1];
	return CurrDept;
}

Engineering *Engineering_Iterator::NextComp(){
	//currently on component
	//check the next element in the tree to see if it is also a component
	//if it is, change current to that component.
	//if next is a department, then make CurrComponent = that Department;
	//and then from there you can link to the next Component in the tree
	return CurrComp;

	// int count = 0;
	// while (CurrDept->getRnD()[CurrDept->getCurrentIndex()] != NULL)
	// {
	// 	CurrDept->setCurrentIndex(CurrDept->getCurrentIndex() + 1);
	// }

	// if(CurrDept->getRnD()[CurrDept->getCurrentIndex() - 1]->getIsDept() == true)
	// CurrDept = CurrDept->getRnD()[CurrDept->getCurrentIndex() - 1];
	// CurrDept->setCurrentIndex(0);
	// return CurrDept;
}

Engineering *Engineering_Iterator::CurrentDept()
{
	return CurrDept;
}

Engineering* Engineering_Iterator::CurrentComp() {
	if(CurrComp == NULL)
	{
		CurrComp = First->getRnD()[0];
	}
	return CurrComp;
}

Engineering* Engineering_Iterator::LastDepartment() {
	// TODO - implement Engineering_Iterator::LastDepartment
	throw "Not yet implemented";
}

Engineering* Engineering_Iterator::LastComp() {
	// TODO - implement Engineering_Iterator::LastComp
	throw "Not yet implemented";
}
