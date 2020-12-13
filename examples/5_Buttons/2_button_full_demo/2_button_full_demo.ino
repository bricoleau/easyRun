#include "easyRun.h"

//wire : pin---btn---GND
const int pin = 2; // =D4 (ESP8266) 

button btn(pin);

void setup()
{
  Serial.begin(115200);
  delay(500);

  Serial.println("\nButton demo");

  Serial.print("pin=");
  Serial.println(btn.pinNumber());

  Serial.print("debounce time=");
  Serial.print(btn.debounce_ms);
  Serial.println(" ms");

  Serial.print("button state is ");
  if (btn.pressed())
  {
    Serial.println("pressed");
  }
  if (btn.released())
  {
    Serial.println("released");
  }

  Serial.println();
}

void loop()
{
  easyRun();

  //several ways to get btn status

  if (btn.changed())
  {
    Serial.print("button state changed to ");
    if (btn.pressed())
    {
      Serial.println("pressed");
    }
    if (btn.released())
    {
      Serial.println("released");
    }
  }  

  if (btn) // or : if (btn.newPress())
  {
    Serial.println("newPress");
  }

  if (btn.newRelease())
  {
    Serial.println("newRelease");
  }

  static uint32_t time_ref = 0;
  if (millis() - time_ref >= 2000)
  {
    time_ref += 2000;
    if (btn.pressed() || btn.time() < 9000)
    {
      Serial.print(".time()=");
      Serial.print(btn.time());
      Serial.print(", .pressTime()=");
      Serial.print(btn.pressTime());
      Serial.print(", .releaseTime()=");
      Serial.print(btn.releaseTime());
      Serial.print(", .pressedFor(5000)=");
      Serial.print(btn.pressedFor(5000) ? "true" : "false");
      Serial.print(", .releasedFor(5000)=");
      Serial.print(btn.releasedFor(5000) ? "true" : "false");
      Serial.println();
    }
  }
}