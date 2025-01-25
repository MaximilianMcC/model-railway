#include "lever.h"
#include <Arduino.h>

//? relayUnit is zero based. relayOpenIndex is not.
Lever::Lever() {}
Lever::Lever(int leverPin, int relayUnit, int relayOpenIndex) {

	// Setup the pin info
	//! Pretty sure pin goes to 0 for some reason. fix (rn (now))
	pin = leverPin;
	pinMode(pin, INPUT_PULLUP);
	previouslyPressed = digitalRead(pin) == LOW;

	// Set the relay info
	this->relayUnit = relayUnit;
	this->relayOpenIndex = relayOpenIndex;
	this->relayCloseIndex = relayOpenIndex + 1;

	// Setup the debounce timer
	// to be 50 milliseconds
	debounceCooldown = Timer(50);
}

void Lever::update() {

	// Check for if the state changed
	// then pulse the required relay
	if (stateChanged()) Serial.println("Changed");
	debounceCooldown.printTimeLeftDebug();

}

bool Lever::stateChanged() {
	
	// Get the current state of the lever
	bool stateChanged = false;
	bool pressed = digitalRead(pin) == LOW;

	// Check for if we're on debounce (was just pressed)
	if (debounceCooldown.hasExpired() == false) {

		// Check for if the state has changed.
		// if it has we pressed the lever
		if (pressed != previouslyPressed) {

			// Start the debounce timer
			debounceCooldown.start();

			// Say that the state changed
			stateChanged = true;
		}
	}

	// Record the state for next time
	previouslyPressed = pressed;

	// Say if the lever has been changed
	return stateChanged;
}