#include "Race_Computations.h"
#include <cstdlib>
#include <time.h>

//Race_Computations* Race_Computations :: instance = 0;

//Race_Computations* Race_Computations:: GetComp() {
//    if(instance==0)
//        instance = new Race_Computations();
//    return instance;
//}

double weightAverage(int t1, int t2) {
    float hold = t1+t2;
    return t1/hold; // avoid integer division
}

// higher score wins
bool Race_Computations::OvertakeSuccess(Racers* ToBeOvertaken, Racers* Overtaker) {
    double one, two;
    int score_one =0, score_two =0;

    // r1 : racing ability -> 5
    // r2 : Handling -> 3
    // r3 : speed -> 4
    // r4 : acceleration -> 4
    // r5 : aggression -> 2

    if(Overtaker->Racer->getValue("racing_ability") > ToBeOvertaken->Racer->getValue("racing_ability"))
        score_one += 5;
    else
        score_two += 5;

    if(Overtaker->Car->getValue("handling") > ToBeOvertaken->Car->getValue("handling"))
        score_one += 3;
    else
        score_two += 3;

    if(Overtaker->Car->getValue("speed") > ToBeOvertaken->Car->getValue("speed"))
        score_one += 4;
    else
        score_two += 4;

    if(Overtaker->Car->getValue("acceleration") > ToBeOvertaken->Car->getValue("acceleration"))
        score_one += 4;
    else
        score_two += 4;

    if(Overtaker->Racer->getValue("aggression") > ToBeOvertaken->Racer->getValue("aggression"))
        score_one += 2;
    else
        score_two += 2;

    if(Overtaker->Racer->getValue("conservation") > ToBeOvertaken->Racer->getValue("conservation") && Overtaker->Racer->getValue("conservation")>50)
        score_one -= 2;

    if(score_two > 14) // luck
        score_one += 1+rand()%5;

    one = weightAverage(score_one, score_two);
    two = 1 - one;

    if(DistributeValue(one)==1)
        return true;
    else
        return false;


}

bool Race_Computations::ChanceOfCrash(Racers* racer, Conditions* cond) {
	double fail = racer->Car->getValue("failure");
	int debuff;
	if(cond->WeatherCond->getState()->getName()=="dry") {
        debuff = 100-racer->Racer->getValue("dry");
    } else if(cond->WeatherCond->getState()->getName()=="wet") {
        debuff = 100-racer->Racer->getValue("wet");
	} else {
        debuff = 100-racer->Racer->getValue("raining");
	}

	int conservation = racer->Racer->getValue("conservation");
	int handling = racer->Car->getValue("handling");

	double weight = (fail+debuff);
	weight /= (debuff+fail+conservation+handling);

    if(DistributeValue(weight)==1)
        return true; // crash course
    else
        return false;
}

bool Race_Computations::ChanceOfRecovery(Racers* driver) {
    int top = driver->Racer->getValue("conservation");
    top += driver->Racer->getValue("racing_ability");
    int bottom = top;
    bottom += driver->Car->getValue("failure");
    bottom += driver->Car->getValue("weight");

    double bot = bottom;
    bot = top/bot;

    if(DistributeValue(bot)==1)
        return true;
    else
        return false;

}

int Race_Computations::ChanceOfPitOvertake(int delay) {
    //COMPUTE DELAY
    if(delay > 12) {
        return (4 + rand() % 8);
    } else if(delay < 5) {
        return (0+rand() % 2);
    } else {
        return (2 + rand() % 5);
    }
}

int Race_Computations::DistributeValue(double value) {
    srand((unsigned) time(0));
    value *=100;
    int x = (int) value;
    int range = 1+ rand() % 100;
    if(range <= x)
        return 1;
    else
        return 0;
}
