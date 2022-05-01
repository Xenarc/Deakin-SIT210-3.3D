/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "g:/Mark/Documents/DOCUMENTS/Deakin/SIT210_Embedded_Systems_Development/3.3D/3-3D/src/3-3D.ino"
#include "HC_SR04/HC_SR04.h"

void setup();
void loop();
#line 3 "g:/Mark/Documents/DOCUMENTS/Deakin/SIT210_Embedded_Systems_Development/3.3D/3-3D/src/3-3D.ino"
const pin_t LED = D7;

SYSTEM_THREAD(ENABLED);

HC_SR04 distanceSensor(D5, D4, 5, 100);

void patHandler(const char* event, const char *data);
void waveHandler(const char* event, const char *data);

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D4, INPUT);
  
  Serial.begin(9600);
  Particle.subscribe("pat", patHandler);
  Particle.subscribe("wave", waveHandler);
}

void flash(const int frequency, const int periods);
void publish(const char* name);

void loop()
{
  double distance = distanceSensor.getDistanceCM();
  
  Serial.printlnf("Distance: %f", distance);
  
  if(distance == -1){
    publish("pat");
  }
  else if(distance < 10.0){
    publish("wave");
  }
  else{
    digitalWrite(LED, LOW);
  }
  delay(500);
}

void publish(const char* name){
  bool success;
  
  do {
    success = Particle.publish(name);
  
    if (!success) {
      delay(1000); // retry after 1 second
      continue;
    }
  } while(!success);
}
void flash(const int frequency, const int periods){
  for (int i = 0; i < periods*2; i++)
  {
    digitalWrite(LED, i % 2 == 0 ? HIGH : LOW);
    delay(frequency/2);
  }
}

void patHandler(const char* event, const char *data){
  flash(500, 3);
}

void waveHandler(const char* event, const char *data){
  flash(100, 15);
}
