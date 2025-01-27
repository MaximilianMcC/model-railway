#include "lever.h"
#include <Arduino.h>

Lever::Lever() {}

// Make a lever that operates between two relays
//? relayUnit is zero based. relayOpenIndex is not.
Lever::Lever(int leverPin, int relayUnit, int relayOpenIndex, bool single) {

	// Setup the pin info
	//! Pretty sure pin goes to 0 for some reason. fix (rn (now))
	pin = leverPin;
	pinMode(pin, INPUT_PULLUP);
	previouslyPressed = digitalRead(pin) == LOW;

	// See if we're using a single relay
	singleRelay = single;

	// Create the needed relays
	openRelay = new Relay(relayUnit, relayOpenIndex);
	if (singleRelay == false) closeRelay = new Relay(relayUnit, relayOpenIndex + 1);

	// Setup the debounce timer
	// to be 50 milliseconds
	debounceCooldown = Timer(50);
}

void Lever::update() {

	// Check for if the state changed
	// then pulse the required relay
	if (stateChanged()) {
		
		// Check for what relay we're after
		// TODO: Don't do this like this
		Relay* relay;
		relay = previouslyPressed ? openRelay : closeRelay;

		// If we're only working with one relay
		// then use the only relay we have
		if (singleRelay) relay = openRelay;

		// Pluse the relay
		relay->beginPulse();
	}

	// Check for if any of the relays
	// need their pulsing to be stopped
	// TODO: Maybe only call on previouslyPressed?
	openRelay->endPulse();
	closeRelay->endPulse();
}

bool Lever::stateChanged() {
	
	// Check for if we're on cooldown rn. If we are
	// then exit early (can't do anything (on cooldown))
	if (debounceCooldown.stillCounting()) return false;

	// Check if the switch is down or up rn
	bool currentlyPressed = digitalRead(pin) == LOW;
	bool changed = previouslyPressed != currentlyPressed;

	// Check for if we've pressed the switch. If we
	// have then rest the debounce cooldown
	if (changed) {

		// Put the switch on a cooldown
		// so we don't get debounce
		debounceCooldown.start();
	}

	// Update the last pressed state then return
	previouslyPressed = currentlyPressed;
	return changed;
}