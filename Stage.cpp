#include "Stage.h"

void Stage::updateStage(Stage* set) {
    curr_stage = set;
}

Stage* Stage::getStage() {
    return curr_stage;
}

