#include "Opposing_Driver.h"
#include <cstdlib>

Opposing_Driver::~Opposing_Driver() {

}

Driver* Opposing_Driver::GenDriver(int skills) {
    Statistics *stats = new Statistics(false, true);
    int rando;
    if(skills > 90) {
        stats->ChangeValue("racing_ability", 80, false);
        rando = 1 + rand() % 20;
        stats->ChangeValue("racing_ability", rando, true, true);

        stats->ChangeValue("preparedness", 100, false);
        stats->ChangeValue("dry", 90, false);
        stats->ChangeValue("wet", 75, false);
        stats->ChangeValue("raining", 70, false);

        stats->ChangeValue("aggression", 50, false);
        rando = 1 + rand() % 40;
        stats->ChangeValue("aggression", rando, true, true);

        stats->ChangeValue("conservation", 50, false);
        stats->ChangeValue("conservation", rando, true, false);

    }
    else if(skills > 80 && skills < 90 ) {
        stats->ChangeValue("racing_ability", 73, false);
        rando = 1 + rand() % 20;
        stats->ChangeValue("racing_ability", rando, true, true);

        stats->ChangeValue("preparedness", 100, false);
        stats->ChangeValue("dry", 83, false);
        stats->ChangeValue("wet", 68, false);
        stats->ChangeValue("raining", 65, false);

        stats->ChangeValue("aggression", 50, false);
        rando = 1 + rand() % 40;
        stats->ChangeValue("aggression", rando, true, true);

        stats->ChangeValue("conservation", 60, false);
        stats->ChangeValue("conservation", rando, true, false);
    }
    else if(skills > 70 && skills < 80 ) {

        stats->ChangeValue("racing_ability", 60, false);
        rando = 1 + rand() % 20;
        stats->ChangeValue("racing_ability", rando, true, true);

        stats->ChangeValue("preparedness", 66, false);
        stats->ChangeValue("dry", 78, false);
        stats->ChangeValue("wet", 63, false);
        stats->ChangeValue("raining", 60, false);

        stats->ChangeValue("aggression", 40, false);
        rando = 1 + rand() % 40;
        stats->ChangeValue("aggression", rando, true, true);

        stats->ChangeValue("conservation", 60, false);
        stats->ChangeValue("conservation", rando, true, false);

    }
    else if(skills > 60 && skills < 70 ) {

        stats->ChangeValue("racing_ability", 55, false);
        rando = 1 + rand() % 20;
        stats->ChangeValue("racing_ability", rando, true, true);

        stats->ChangeValue("preparedness", 66, false);
        stats->ChangeValue("dry", 70, false);
        stats->ChangeValue("wet", 58, false);
        stats->ChangeValue("raining", 54, false);

        stats->ChangeValue("aggression", 40, false);
        rando = 1 + rand() % 40;
        stats->ChangeValue("aggression", rando, true, true);

        stats->ChangeValue("conservation", 60, false);
        stats->ChangeValue("conservation", rando, true, false);

    }
    else {
        stats->ChangeValue("racing_ability", 50, false);
        rando = 1 + rand() % 20;
        stats->ChangeValue("racing_ability", rando, true, true);

        stats->ChangeValue("preparedness", 33, false);
        stats->ChangeValue("dry", 65, false);
        stats->ChangeValue("wet", 53, false);
        stats->ChangeValue("raining", 50, false);

        stats->ChangeValue("aggression", 35, false);
        rando = 1 + rand() % 40;
        stats->ChangeValue("aggression", rando, true, true);

        stats->ChangeValue("conservation", 50, false);
        stats->ChangeValue("conservation", rando, true, false);
    }

    Driver *newDriver = new Driver();
    newDriver->setStats(stats);

    return newDriver;
}