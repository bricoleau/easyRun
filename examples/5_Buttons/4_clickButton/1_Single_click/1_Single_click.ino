#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void click()
{
  Serial.println("click");
}

clickButton btn(pin, click);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}