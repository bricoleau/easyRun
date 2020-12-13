#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void shortPress1() {Serial.println("Short press single click");}
void shortPress2() {Serial.println("Short press double click");}
void shortPress3() {Serial.println("Short press triple click");}

void longPress1() {Serial.println("Long press single click");}
void longPress2() {Serial.println("Long press double click");}
void longPress3() {Serial.println("Long press triple click");}

press3Button btn(pin, shortPress1, longPress1, shortPress2, longPress2, shortPress3, longPress3);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}