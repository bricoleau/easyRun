#include "easyLed.h"

#if defined(AVR)
  #define LED_PWM_RANGE 256
#else
  #define LED_PWM_RANGE 1024
#endif

easyLed::easyLed(uint8_t pin, bool light_on_LOW)
{
  setPin(pin, light_on_LOW);
}

void easyLed::setPin(uint8_t pin, bool light_on_LOW)
{
  pinMode(pin, OUTPUT);
  _setPin(pin);
  _setInvert(light_on_LOW);
  _setHasPWM(digitalPinHasPWM(pin));
  _value = 255;
  set(0);
}

void easyLed::set(uint8_t value)
{
  if (value != _value)
  {
    _value = value;
    if (lightOnLOW())
    {
       value = 255 - value;
    }
    if (value == 0)
    {
      digitalWrite(pin(), LOW);
    }
    else if (value == 255)
    {
      digitalWrite(pin(), HIGH);
    }
    else if (hasPWM())
    {
      if (LED_PWM_RANGE == 1024)
      {
        uint16_t val = value << 2;
        analogWrite(pin(), val);
      }
      else
      {
        analogWrite(pin(), value);
      }
    }
    else
    {
      digitalWrite(pin(), value > 127 ? HIGH : LOW);
    }
  }
}

