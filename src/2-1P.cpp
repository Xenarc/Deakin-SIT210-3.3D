/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "g:/Mark/Documents/DOCUMENTS/Deakin/SIT210_Embedded_Systems_Development/2.1P/2-1P/src/2-1P.ino"
#include "morse.h"

void setup();
void loop();
#line 3 "g:/Mark/Documents/DOCUMENTS/Deakin/SIT210_Embedded_Systems_Development/2.1P/2-1P/src/2-1P.ino"
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
