#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

//Demo : adjusting time using only one button
//Single click and hold : increase hours
//Double click and hold : increase minutes
//Triple click and hold : increase seconds

int hours   = 12;
int minutes =  0;
int seconds =  0;

void print2digits(int number)
{
  if (number < 10) Serial.print('0');
  Serial.print(number);
}

void printTime()
{
  print2digits(hours);
  Serial.print(':');
  print2digits(minutes);
  Serial.print(':');
  print2digits(seconds);
  Serial.println();
}

uint32_t timeRef;

void press()
{
  timeRef = 0;
}

//this will increase speed when button is held for a long time
uint32_t next(uint32_t time)
{
  if (time <  1000) return 1000; //increase value each 1000 ms
  if (time <  3000) return  500; //increase value each  500 ms
  if (time <  6000) return  250; //increase value each  250 ms
  if (time < 10000) return  100; //increase value each  100 ms
  return 50;                     //increase value each   50 ms  
}

void hold1(uint32_t time)
{
  if (time >= timeRef)
  {
    hours = (hours + 1) % 24;
    printTime();
    timeRef = timeRef + next(time);
  }
}

void hold2(uint32_t time)
{
  if (time >= timeRef)
  {
    minutes = (minutes + 1) % 60;
    printTime();
    timeRef = timeRef + next(time);
  }
}

void hold3(uint32_t time)
{
  if (time >= timeRef)
  {
    seconds = (seconds + 1) % 60;
    printTime();
    timeRef = timeRef + next(time);
  }
}

hold3Button btn(pin, press, hold1, hold2, hold3);

void setup()
{
  Serial.begin(115200);
  delay(500);
  printTime();
}

void loop()
{
  easyRun();
}