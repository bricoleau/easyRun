#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

//You will increase/decrease this value by single/double click and hold button
int value = 0;

void setValue(int new_value)
{
  value = new_value;
  Serial.println(value);
}

void setup()
{
  Serial.begin(115200);
  delay(500);
  setValue(0);
}

uint32_t timeRef = 0;

void press()
{
  timeRef = 0;
}

//this will increase speed when button is held for a long time
uint32_t next(uint32_t time)
{
  if (time <  1000) return 1000; //increase/decrease value each 1000 ms
  if (time <  3000) return  500; //increase/decrease value each  500 ms
  if (time <  6000) return  250; //increase/decrease value each  250 ms
  if (time < 10000) return  100; //increase/decrease value each  100 ms
  return 50;                     //increase/decrease value each   50 ms  
}

void increase(uint32_t time)
{
  if (time >= timeRef)
  {
    setValue(value + 1);
    timeRef = timeRef + next(time);
  }
}

void decrease(uint32_t time)
{
  if (time >= timeRef)
  {
    setValue(value - 1);
    timeRef = timeRef + next(time);
  }
}

hold2Button btn(pin, press, increase, decrease);

void loop()
{
  easyRun();
}