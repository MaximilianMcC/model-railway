#include <Arduino.h>
#include "lever.h"

const int LeverCount = 15;
Lever Levers[LeverCount];

void setup() {

	// Register all the serial ports
	const int baudRate = 9600;
	Serial.begin(baudRate);
	Serial1.begin(baudRate);
	Serial2.begin(baudRate);
	Serial3.begin(baudRate);

	// Set what levers go to what relays
	// TODO: Don't hardcode (json or something)
	// Levers[0] = Lever(2, 0, 1, false);
	Levers[0] = Lever(2, 0, 1, true);
}

void loop() {
	
	// Update all levers
	for (int i = 0; i < LeverCount; i++) {

		Levers[i].update();
	}
}