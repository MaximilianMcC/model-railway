#include <Arduino.h>

class Lever {
	
public:
	Lever(int pin, int relayUnit, int relayOpenIndex);
	~Lever();

	void Update();

private:
	
};

//? relayUnit is zero based. relayOpenIndex is not.
Lever::Lever(int pin, int relayUnit, int relayOpenIndex) {

}

void Lever::Update() {

}
