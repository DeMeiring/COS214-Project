#ifndef COMMAND_H
#define COMMAND_H

class Command {

private:
	Radio_System* Comms;
	string command_name;

public:
	void setReceiver(Radio_System* rec);

	void ForwardCommand(Race_Crew* RaceMember);
};

#endif
