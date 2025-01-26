#pragma once

#include <Arduino.h>
#include "timer.h"
#include "relay.h"

class Lever {
public:
	Lever();
	Lever(int leverPin, int relayUnit, int relayOpenIndex);

	void update();
	
	bool stateChanged();

private:
	int pin;

	Relay* openRelay;
	Relay* closeRelay;

	Timer debounceCooldown;
	bool previouslyPressed;
};