#ifndef LEVER_H
#define LEVER_H

#include <Arduino.h>
#include "timer.h"

class Lever {
public:
	Lever();
	Lever(int leverPin, int relayUnit, int relayOpenIndex);

	void update();
	
	bool stateChanged();

private:
	int pin;

	int relayUnit;
	int relayOpenIndex;
	int relayCloseIndex;

	Timer debounceCooldown;
	bool previouslyPressed;
};

#endif
