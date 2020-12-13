#include "easyRun.h"

/*
easyLed provides a standalone led driver including PWM

see easyLed.h for complete list of properties and methods
*/

easyLed led(LED_BUILTIN);

void setup()
{
}

void loop()
{
  led.toggle();
  delay(1000);
}