#include "easyRun.h"

int value = LOW;

void blinker()
{
  value = (value == HIGH) ? LOW : HIGH;
  digitalWrite(LED_BUILTIN, value);
} 
periodicTask t(blinker, 1000);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  easyRun();
}
