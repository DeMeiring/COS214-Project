#ifndef ENGINEERING_ITERATOR_H
#define ENGINEERING_ITERATOR_H

class Engineering_Iterator {

private:
	Engineering* CurrDept;
	Engineering* CurrComp;

public:
	Engineering* NextDept();

	Engineering* NextComp();

	Engineering* CurrentDept();

	Engineering* CurrComp();

	Engineering* LastDepartment();

	Engineering* LastComp();
};

#endif
