#include "Pit_Stop.h"
#include <cstdlib>

Pit_Stop::Pit_Stop() {
    nextTyreSet = nullptr;
    tyre_swaps = 4;
}

void Pit_Stop::tyreSwap(int tyre_type) {
    if(tyre_swaps>0 && nextTyreSet==nullptr) {
        tyre_swaps--;
        nextTyreSet = new tyre_swap();
        switch (tyre_type) {
            case 1: {
                nextTyreSet->type = "Softs";
                nextTyreSet->tyre = new Soft();
                nextTyreSet->delay = 2;
                break;
            }
            case 2: {
                nextTyreSet->type = "Medium";
                nextTyreSet->tyre = new Medium();
                nextTyreSet->delay = 2;
                break;
            }
            case 3: {
                nextTyreSet->type = "Hard";
                nextTyreSet->tyre = new Hard();
                nextTyreSet->delay = 2;
                break;
            }
        }
    }
}

int Pit_Stop::Pit_stop_main() {
    int delay =0;
    cout << "The team car pulls in for a pit stop" << endl;
    cout << "The driver is waiting..." << endl;
    if(car_is_damaged && fast_pit) {
        cout << "The damaged car is repaired with a desire to return the track the main concern" << endl;
        delay +=3;
    } else if(car_is_damaged) {
        cout << "The car is repaired with care, with the long term performance of the car in main concern" << endl;
        delay+=7;
    }

    int rando = 1+ rand() % 100;
    if(rando<26 || nextTyreSet== nullptr) {
        if(nextTyreSet== nullptr) {
            tyreSwap(2);
            tyre_swaps++;
        }
        cout << "The driver is waiting for the tyres but they haven't arrived!" << endl; // RIP Daniel Ricciardo
        cout << "The driver falls behind in the race" << endl;
        delay += 12;
    }

    cout << "The tyres of the car are swapped to " << nextTyreSet->type << endl;
    // swap_driver_tyres
    delay += nextTyreSet->delay;

    delete nextTyreSet;
    nextTyreSet = nullptr;

    //COMPUTE DELAY
    if(delay > 12) {
        return (4 + rand() % 8);
    } else if(delay < 5) {
        return (0+rand() % 2);
    } else if(delay < 12 && delay > 5) {
        return (2 + rand() % 5);
    }
}
