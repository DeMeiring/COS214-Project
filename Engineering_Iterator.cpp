#include "Engineering_Iterator.h"
#include "Department.h"
Engineering_Iterator::Engineering_Iterator(Engineering *first){
	this->First = first;
	this->CurrDept = first;
	this->Current = first;
	CurrDept->setDeptIndex(0);
	Current->setCompIndex(0);
	CurrComp = First->getRnD()[0];
	flag = true;
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
	//we are currently pointing to a department
	if(Current->getIsDept() == true && flag == true)
	{
		flag = false;
		Current->setCompIndex(Current->getCompIndex() + 1);
		CurrComp = Current->getRnD()[Current->getCompIndex()];
	}	
	else{
		Current->setCompIndex(Current->getCompIndex() + 1);
		if(Current->getRnD()[Current->getCompIndex()]->getIsDept() == false)
			CurrComp = Current->getRnD()[Current->getCompIndex()];
		else
		{
			flag = true;
			Current = Current->getRnD()[Current->getCompIndex()];
			Current->setCompIndex(0);
			CurrComp = Current->getRnD()[Current->getCompIndex()];
		
		}
		
	}

	return CurrComp;	
}

Engineering *Engineering_Iterator::CurrentDept()
{
	return CurrDept;
}

Engineering* Engineering_Iterator::CurrentComp() {
	return CurrComp;
}

void Engineering_Iterator::resetCurrComp()
{

	this->Current = First;
	
	this->Current->setCompIndex(0);
	this->CurrComp = Current->getRnD()[0];
}

void Engineering_Iterator::resetCurrDept()
{
	this->CurrDept = First;
	CurrDept->setDeptIndex(0);
}

// Engineering* Engineering_Iterator::LastComp() {
// 	// TODO - implement Engineering_Iterator::LastComp
// 	resetCurrComp();
// 	Engineering *Temp = CurrComp;
// 	while(CurrComp != NULL)
// 	{
// 		CurrComp = NextComp();
// 		if(CurrComp != NULL)
// 		{
// 			Temp = CurrComp;
// 		}
// 	}
// 	resetCurrComp();
// 	return Temp;
// }

// Engineering* Engineering_Iterator::LastDepartment() {
// 	// TODO - implement Engineering_Iterator::LastDepartment
// 	throw "Not yet implemented";
// }

