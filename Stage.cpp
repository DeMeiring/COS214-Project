#include "Stage.h"
#include "Client.h"

Stage::Stage(Client* cl) {
    User = cl;
}

Client* Stage::getClient() {
    return User;
}

void Stage::updateStage(Stage* set) {
    curr_stage = set;
}

Stage* Stage::getStage() {
    return curr_stage;
}

