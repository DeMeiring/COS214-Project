#include "Opposing_Team.h"

tuple<OpposingDriver*, OpposingDriver*> Opposing_Team::GenerateTeam(string DriverName1, string DriverName2, int difficulty, bool lowDiff=false){
    OpposingDriver* one = new OpposingDriver;
    one->name = DriverName1;
    one->car = OppCarFact->GenCar(difficulty);
    one->driver = OppDrivFact->GenDriver(difficulty);

    OpposingDriver* two = new OpposingDriver;
    two->name = DriverName1;
    if(!lowDiff)
        difficulty -=25; // tweak
    else
        difficulty -= 5;
    two->car = OppCarFact->GenCar(difficulty);
    two->driver = OppDrivFact->GenDriver(difficulty);

    tuple<OpposingDriver*, OpposingDriver*> toRet;
    toRet = make_tuple(one, two);
    return toRet;
}