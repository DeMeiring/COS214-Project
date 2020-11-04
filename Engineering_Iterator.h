#ifndef ENGINEERING_ITERATOR_H
#define ENGINEERING_ITERATOR_H


#include "Engineering.h"

class Engineering;
class Engineering_Iterator{

private:
	Engineering* CurrDept;
	Engineering* CurrComp;

public:
	Engineering* NextDept();

	Engineering* NextComp();

	Engineering* CurrentDept();

	Engineering* CurrentComp();

	Engineering* LastDepartment();

	Engineering* LastComp();
};

#endif
