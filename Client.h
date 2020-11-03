#ifndef CLIENT_H
#define CLIENT_H

class Client {

private:
	Stage* Stage;
	Transport* Cars;
	Statistics* car_stats;
	Diver_Management* DriverManager;

public:
	void SetStage();

	void run();

	Transport* getCars();

	void setCars(Transport* Cars);

	boolean Store_carStats(Statistics* stats);

	Statistics* getCar_stats();

	void setCar_stats(Statistics* car_stats);
};

#endif
