const pin_t LED = D7;

SYSTEM_THREAD(ENABLED);

void setup()
{
	pinMode(LED, OUTPUT);
}

void loop()
{
	digitalWrite(LED, HIGH);
  
	delay(1s);
  
	digitalWrite(LED, LOW);
  
	delay(1s);
}
