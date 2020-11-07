#include "Conservative.h"

Conservative::Conservative(Statistics *skillModifier) : RaceDay_Strat(skillModifier)
{
    this->aggression = 8;
    this->conservative = 25;
}


int Conservative::getAggression()
{
    return this->aggression;
}

int Conservative::getConservative()
{
    return this->conservative;
}

Conservative::~Conservative()
{
    
}