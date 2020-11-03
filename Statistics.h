#ifndef STATISTICS_H
#define STATISTICS_H

class Statistics {

private:
	tuple<string, int> values;

public:
	Statistics();

	int GetValueByName(string find);

	void SetValue(string name, int value);
};

#endif
