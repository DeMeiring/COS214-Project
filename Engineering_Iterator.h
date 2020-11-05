#ifndef ENGINEERING_ITERATOR_H
#define ENGINEERING_ITERATOR_H

#include <iostream>
#include <string>

using namespace std;

class Engineering;

class Engineering_Iterator
{
private:
	Engineering* CurrDept;
	Engineering* CurrComp;
	Engineering *Current;
	Engineering* First;
	bool flag;

public:
	Engineering_Iterator(Engineering*);

	Engineering* NextDept();

	Engineering* NextComp();

	Engineering* CurrentDept();

	Engineering* CurrentComp();

	Engineering* LastDepartment();

	Engineering* LastComp();
};

#endif
