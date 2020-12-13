#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void on1() {Serial.println("1 on");}
void on2() {Serial.println("2 on");}

void off1() {Serial.println("1 off");}
void off2() {Serial.println("2 off");}

toggle2Button btn(pin, on1, off1, on2, off2);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}