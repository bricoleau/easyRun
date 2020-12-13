#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void on()
{
  Serial.println("on");
}

void off()
{
  Serial.println("off");
}

toggleButton btn(pin, on, off);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}