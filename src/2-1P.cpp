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
String str = "";

SYSTEM_THREAD(ENABLED);

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin();
}

void loop()
{
  Serial.println("Type what you want to say in morse: ");
  
  // Dont do anything if there is nothing to print
  while(!Serial.available()) {}
  
  // Get the string from the buffer
  str = Serial.readString();
  // Print it back to the user
  Serial.println(str);
  // Print it as morse code
  Morse::printMorse(str, LED);
}
