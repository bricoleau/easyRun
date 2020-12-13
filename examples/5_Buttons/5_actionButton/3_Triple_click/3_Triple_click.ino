#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void pressed1() {Serial.println("Pressed single click");}
void pressed2() {Serial.println("Pressed double click");}
void pressed3() {Serial.println("Pressed triple click");}

void released1() {Serial.println("Released from single click");}
void released2() {Serial.println("Released from double click");}
void released3() {Serial.println("Released from triple click");}

action3Button btn(pin, pressed1, released1, pressed2, released2, pressed3, released3);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}