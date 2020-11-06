#include "Weather.h"

Statistics* Weather::getStats() {
	return stats;
}

Dry::Dry() {
	setNextState(new Wet());
}

Wet::Wet() {
	setNextState(new Raining());
}

Raining::Raining() {
	setNextState(new Dry());
}
