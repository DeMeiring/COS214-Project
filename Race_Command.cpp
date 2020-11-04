#include "Race_Command.h"

void Race_Command::ForwardCommand() {
        getRec()->PushCommand(getInvoker(), this);
        // pass command and invoker to receiver -> mediator
}