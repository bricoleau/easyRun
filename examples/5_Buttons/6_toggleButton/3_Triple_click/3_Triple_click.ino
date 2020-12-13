#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

void on1() {Serial.println("1 on");}
void on2() {Serial.println("2 on");}
void on3() {Serial.println("3 on");}

void off1() {Serial.println("1 off");}
void off2() {Serial.println("2 off");}
void off3() {Serial.println("3 off");}

toggle3Button btn(pin, on1, off1, on2, off2, on3, off3);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}