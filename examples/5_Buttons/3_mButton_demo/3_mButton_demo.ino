#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

//mButton can handle multiple clicks

//try double clicks or triple clicks
const int maxClicks = 4;
mButton btn(pin, maxClicks); 

void setup()
{
  Serial.begin(115200);
  delay(500);

  Serial.println("\nmButton demo");

  Serial.print("pin=");
  Serial.println(btn.pinNumber());

  Serial.print("debounce time=");
  Serial.print(btn.debounce_ms);
  Serial.println(" ms");

  Serial.print("max time between clicks=");
  Serial.print(btn.MAX_TIME_BETWEEN_CLICKS);
  Serial.println(" ms");
}

void loop()
{
  easyRun();

  if (btn)
  {
    Serial.print("pressed with ");
    switch (btn.clicks)
    {
      case 1 : Serial.println("single click"); break;
      case 2 : Serial.println("double click"); break;
      case 3 : Serial.println("triple click"); break;
      default :
        Serial.print(btn.clicks);
        Serial.println(" clicks");      
    }
  }
  
  if (btn.newRelease())
  {
    Serial.print("released from ");
    switch (btn.clicks)
    {
      case 1 : Serial.println("single click"); break;
      case 2 : Serial.println("double click"); break;
      case 3 : Serial.println("triple click"); break;
      default :
        Serial.print(btn.clicks);
        Serial.println(" clicks");      
    }
  }
}