#include "morse.h"

const pin_t LED = D7;

SYSTEM_THREAD(ENABLED);

void setup()
{
	pinMode(LED, OUTPUT);
}

void loop()
{
	Morse::printMorse("Mark", LED);
}
