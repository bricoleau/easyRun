#include "easyRun.h"

/*
easyLed provides a standalone led driver including PWM

Declaration : easyLed(uint8_t pin, bool light_on_LOW = false)

Dimming rules :
- dimming range is 0-255, even with 10bits PWM boards (ESP8266)
-   0 = light OFF
- 255 = light max ON
- if led is not wired to a PWM pin, 0-127 is considered as 0, and 128-255 is considered as 255

see easyLed.h for complete list of properties and methods
*/

easyLed led(LED_BUILTIN, LED_BUILTIN_LIGHT_ON_LOW);

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.println(F("\nLed dimming demo"));

  Serial.print(F("Led is wired to pin"));
  Serial.print(led.pin());
  Serial.print(F(", light on "));
  Serial.print(led.lightOnLOW() ? F("LOW") : F("HIGH"));
  Serial.print(F(" with "));
  if(!led.hasPWM()) Serial.print(F("no "));
  Serial.println(F("PWM available."));
  Serial.println();

  Serial.print(F("Current dimming value is "));
  Serial.println(led.value());
}

bool ask = true;

void loop()
{
  if (ask)
  {
    Serial.print(F("Enter dimming value 0-255 >"));
    ask = false;
  }
  if (Serial.available())
  {
    int value = Serial.parseInt();
    Serial.println(value);
    led.set(value);
    ask = true;
  }
}