#pragma once

#include <Arduino.h>
#include "timer.h"
#include "relay.h"

class Lever {
public:
	Lever();
	Lever(int leverPin, int relayUnit, int relayOpenIndex, bool single);

	void update();
	
	bool stateChanged();

private:
	int pin;

	bool singleRelay;
	Relay* openRelay;
	Relay* closeRelay;

	Timer debounceCooldown;
	bool previouslyPressed;
};