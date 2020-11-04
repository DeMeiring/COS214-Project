#ifndef CLIENT_H
#define CLIENT_H

#include "Stage.h"
#include "Engineering.h"
#include "Transport.h"
#include "Driver_Management.h"
#include "Statistics.h"

class Client {

private:
	Stage* Stage;
	Transport* Cars;
	Statistics* car_stats;
	Driver_Management* DriverManager;

public:

	Client();
	virtual ~Client();

	void SetStage();

	void run();

	Transport* getCars();

	void setCars(Transport* Cars);

	bool Store_carStats(Statistics* stats);

	Statistics* getCar_stats();

	void setCar_stats(Statistics* car_stats);
};

#endif
