#include "relay.h"

#define OPEN_RELAY 'O'
#define CLOSE_RELAY 'C'
#define TOGGLE_RELAY 'T'

Relay::Relay(int relayUnit, int relayIndex)
{
	// Assign the index
	index = relayIndex;

	// Get the required serial port for the relay
	switch (relayUnit) {

		case 1: serialPort = &Serial1; break;
		case 2: serialPort = &Serial2; break;
		case 3: serialPort = &Serial3; break;
		default: serialPort = &Serial; break;
	}

	// Make the pulse timer to
	// go for 100 milliseconds
	//? + 10 is because theres a 10ms delay to let the serial send
	pulseClock = Timer(100 + 10);
}

void Relay::executeCommand(char commandType) {

	// Make the command
	char command[10];
	sprintf(command, "AT+%c%d", commandType, index);

	// Run the command
	//? the delay is to give the serial thingy
	//? time to actually send the command (cpp heaps faster than ino)
	//? Pretty sure flush make the execution blocking until all data is sent
	serialPort->println(command);
	serialPort->flush();
	delay(10);
}

void Relay::beginPulse() {

	// Begin the pulse timer so we know
	// when to turn off the relay
	pulseClock.start();
	currentlyInAPulse = true;

	// Open the relay to begin the pulse
	executeCommand(OPEN_RELAY);
}

void Relay::endPulse() {
	
	// Return if theres no pulse to stop
	if (currentlyInAPulse == false) return;

	// Check for if the time is up
	if (pulseClock.stillCounting() == false)
	{
		// Close the relay to end the pulse
		executeCommand(CLOSE_RELAY);

		// Say that the pulse is done
		currentlyInAPulse = false;
	}
}