#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

button btn(pin);

//see button.h for complete list of properties and methods 

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();

  if (btn)
  {
    Serial.println("Pressed");
  }
}