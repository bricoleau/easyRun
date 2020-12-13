#include "easyRun.h"

asyncTask blinker;

void low();
void high();

void low()
{
  digitalWrite(LED_BUILTIN, LOW);
  blinker.set(high, 1000);
} 

void high()
{
  digitalWrite(LED_BUILTIN, HIGH);
  blinker.set(low, 1000);
} 

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  blinker.set(high, 0);
}

void loop()
{
  easyRun();
}
