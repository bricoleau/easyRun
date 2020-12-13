#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void shortPress()
{
  Serial.println("Short press");
}

void longPress()
{
  Serial.println("Long press");
}

pressButton btn(pin, shortPress, longPress);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}