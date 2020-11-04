#ifndef CLIENT_H
#define CLIENT_H
#include "Stage.h"
#include "Transport.h"
#include "Statistics.h"
//#include "DriverManager.h"


class Client {

private:
	Stage* Stage;
	Transport* Cars;
	Statistics* car_stats;
//	Diver_Management* DriverManager;

public:
	void SetStage();

	void run();

	Transport* getCars();

	void setCars(Transport* Cars);

	bool Store_carStats(Statistics* stats);

	Statistics* getCar_stats();

	void setCar_stats(Statistics* car_stats);
};

#endif
