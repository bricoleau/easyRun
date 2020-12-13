#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void pressed()
{
  Serial.println("Pressed");
}

void released()
{
  Serial.println("Released");
}

actionButton btn(pin, pressed, released);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}