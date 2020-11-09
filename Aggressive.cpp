#include "Aggressive.h"


Aggressive::Aggressive(Statistics *skillModifier) : RaceDay_Strat(skillModifier)
{
    this->aggression = 25;
    this->conservative = 15;
}


int Aggressive::getAggression()
{
    return this->aggression;
}

int Aggressive::getConservative()
{
    return this->conservative;
}

Aggressive::~Aggressive()
{
    
}