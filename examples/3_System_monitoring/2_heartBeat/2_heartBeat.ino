#include "easyRun.h"

/*
heartBeat provides a lightning pulse on builtin led
It allows a first visual check of system fluidity

Better used on boards with pwm available on builtin led.
Unfortunatly, avr boards (uno, mega, ...) have no pwm on builtin led.
You may wire a led to a pwm pin :
heartBeat hb(2000, pwm_pin);

see heartBeat.h for complete list of properties and methods
*/

heartBeat hb;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}