#include "Race_Command.h"
#include "Radio_System.h"

Race_Command::Race_Command(Radio_System* rec, Race_Crew* invoker, string command) : Command(command, rec, invoker) {

}

void Race_Command::ForwardCommand() {
        getRec()->PushCommand(getInvoker(), this);
        // pass command and invoker to receiver -> mediator
}

Race_Command::~Race_Command() {}