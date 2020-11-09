#include "Opposing_Team.h"

tuple<OpposingDriver*, OpposingDriver*> Opposing_Team::GenerateTeam(string DriverName1, string DriverName2, int difficulty, bool lowDiff){
    OpposingDriver* one = new OpposingDriver;
    one->name = DriverName1;
    one->car = OppCarFact->GenCar(difficulty);
    one->driver = new Driver(nullptr,OppDrivFact->GenDriver(difficulty),DriverName1,0);

    OpposingDriver* two = new OpposingDriver;
    two->name = DriverName1;
    if(!lowDiff)
        difficulty -=25; // tweak
    else
        difficulty -= 5;
    two->car = OppCarFact->GenCar(difficulty);
    two->driver = new Driver(nullptr,OppDrivFact->GenDriver(difficulty),DriverName2,0);

    tuple<OpposingDriver*, OpposingDriver*> toRet;
    toRet = make_tuple(one, two);
    return toRet;
}