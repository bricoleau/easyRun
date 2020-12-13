#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void click1() {Serial.println("single click");}
void click2() {Serial.println("double click");}
void click3() {Serial.println("triple click");}

click3Button btn(pin, click1, click2, click3);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}