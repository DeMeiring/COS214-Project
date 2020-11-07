#include "Risky.h"

Risky::Risky(Statistics *skillModifier) : RaceDay_Strat(skillModifier)
{
    this->aggression = 15;
    this->conservative = 20;
}


int Risky::getAggression()
{
    return this->aggression;
}

int Risky::getConservative()
{
    return this->conservative;
}

Risky::~Risky()
{
    
}