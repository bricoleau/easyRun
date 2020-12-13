#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

unsigned long timeRef = 0;

void press()
{
  Serial.println("Pressed");
  timeRef = 0;
}

void hold(uint32_t time)
{
  if (time >= timeRef)
  {
    Serial.print(time);
    Serial.println(" ms");
    timeRef = timeRef + 500; //next print in 500 ms
  }
}

holdButton btn(pin, press, hold);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}