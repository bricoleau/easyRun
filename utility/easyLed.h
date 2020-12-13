#ifndef easyLed_h
#define easyLed_h

#include <Arduino.h>

#if defined(AVR)
const bool LED_BUILTIN_LIGHT_ON_LOW = false;
#else
const bool LED_BUILTIN_LIGHT_ON_LOW = true;
#endif

class easyLed
{
  public :
    easyLed(uint8_t pin, bool light_on_LOW = false);
    void setPin(uint8_t pin, bool light_on_LOW = false);

    void set(uint8_t value);
    inline uint8_t value() const {return  _value;}

    inline void on()  {set(255);}
    inline void off() {set(0);}

    inline bool isOff()   const {return value() == 0;}
    inline bool isOn()    const {return value() >  0;}
    inline bool isMaxOn() const {return value() == 255;}

    inline void setOnOff(bool ON) {set(ON ? 255 : 0);} 
    inline void toggle() {setOnOff(isOff());}

    inline void stepUp(uint8_t step = 1)   {set((step >= 255 - value()) ? 255 : value() + step);}
    inline void stepDown(uint8_t step = 1) {set((step >= value()) ? 0 : value() - step);}

    inline uint8_t pin()     const {return  _status & 0b00111111;} 
    inline bool lightOnLOW() const {return (_status & 0b01000000) != 0;}
    inline bool hasPWM()     const {return (_status & 0b10000000) != 0;}

  protected :
    uint8_t _value;
    uint8_t _status;
    inline void _setPin(uint8_t pin)    {_status = (_status & 0b11000000) | (pin & 0b00111111);}
    inline void _setInvert(bool litLOW) {_status = litLOW ? _status | 0b01000000 : _status & 0b10111111;}
    inline void _setHasPWM(bool hasPWM) {_status = hasPWM ? _status | 0b10000000 : _status & 0b01111111;}
};

#endif