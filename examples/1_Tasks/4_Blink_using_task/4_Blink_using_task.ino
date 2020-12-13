#include "easyRun.h"

unsigned long timeRef = 0;
int value = LOW;

void blinker()
{

  if (millis() - timeRef >= 1000)
  {
    timeRef = millis();
    value = (value == HIGH) ? LOW : HIGH;
    digitalWrite(LED_BUILTIN, value);
  }
} 
task t(blinker);

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  easyRun();
}
