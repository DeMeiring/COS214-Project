#include "Command.h"
#include "Race_Crew.h"

Command::Command(string command, Radio_System* receiver, Race_Crew* rc) {

	Comms = receiver;
	command_name = command;
	invoker = rc;

}

Radio_System* Command::getRec() {
	return Comms;
}

Race_Crew* Command::getInvoker() {
	return invoker;
}

string Command::getCommand() {
	return command_name;
}