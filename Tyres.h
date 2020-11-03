#ifndef TYRES_H
#define TYRES_H

class Tyres {

private:
	int degradation;

public:
	virtual void reduceTyre() = 0;
};

#endif
