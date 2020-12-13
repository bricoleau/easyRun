#ifndef holdButton_h
#define holdButton_h

#include "button.h"
#include "callbacks.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//holdButton for handling events :
//single click
//
//hold2Button for handling events :
//single click
//double click
//
//hold3Button for handling events :
//single click
//double click
//triple click
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class holdButtonGen : public hookedButton
{
  public :
    holdButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hookedButton(pinNumber, debounce) {}

    virtual void runPress() = 0;
    virtual void runHold(uint32_t time) = 0;
  protected :
    void hook();
};

class holdButton : public holdButtonGen
{
  public :
    callbackVoid callback_press;
    callbackTime callback_hold;

    holdButton(
      uint8_t pin,
      callbackVoid::callback_t custom_press,
      callbackTime::callback_t custom_hold,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      holdButtonGen(pin, debounce_ms),
      callback_press(custom_press),
      callback_hold(custom_hold)
    {}

    inline void runPress() {callback_press.execute();}
    inline void runHold(uint32_t time) {callback_hold.execute(time);}
};

class hold2ButtonGen : public hooked2Button
{
  public :
    hold2ButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hooked2Button(pinNumber, debounce) {}

    virtual void runPress1() = 0;
    virtual void runHold1(uint32_t time) = 0;
    virtual void runPress2() = 0;
    virtual void runHold2(uint32_t time) = 0;
  protected :
    void hook();
};

class hold2Button : public hold2ButtonGen
{
  public :
    callbackVoid callback_press1, callback_press2;
    callbackTime callback_hold1, callback_hold2;

    hold2Button(
      uint8_t pin,
      callbackVoid::callback_t custom_press1,
      callbackTime::callback_t custom_hold1,
      callbackVoid::callback_t custom_press2,
      callbackTime::callback_t custom_hold2,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      hold2ButtonGen(pin, debounce_ms),
      callback_press1(custom_press1),
      callback_press2(custom_press2),
      callback_hold1(custom_hold1),
      callback_hold2(custom_hold2)
    {}

    hold2Button(
      uint8_t pin,
      callbackVoid::callback_t custom_press1,
      callbackTime::callback_t custom_hold1,
      callbackTime::callback_t custom_hold2,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      hold2ButtonGen(pin, debounce_ms),
      callback_press1(custom_press1),
      callback_press2(custom_press1),
      callback_hold1(custom_hold1),
      callback_hold2(custom_hold2)
    {}

    inline void runPress1() {callback_press1.execute();}
    inline void runPress2() {callback_press2.execute();}
    inline void runHold1(uint32_t time) {callback_hold1.execute(time);}
    inline void runHold2(uint32_t time) {callback_hold2.execute(time);}
};

class hold3ButtonGen : public hooked3Button
{
  public :
    hold3ButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hooked3Button(pinNumber, debounce) {}

    virtual void runPress1() = 0;
    virtual void runHold1(uint32_t time) = 0;
    virtual void runPress2() = 0;
    virtual void runHold2(uint32_t time) = 0;
    virtual void runPress3() = 0;
    virtual void runHold3(uint32_t time) = 0;
  protected :
    void hook();
};

class hold3Button : public hold3ButtonGen
{
  public :
    callbackVoid callback_press1, callback_press2, callback_press3;
    callbackTime callback_hold1,  callback_hold2,  callback_hold3;

    hold3Button(
      uint8_t pin,
      callbackVoid::callback_t custom_press1,
      callbackTime::callback_t custom_hold1,
      callbackVoid::callback_t custom_press2,
      callbackTime::callback_t custom_hold2,
      callbackVoid::callback_t custom_press3,
      callbackTime::callback_t custom_hold3,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      hold3ButtonGen(pin, debounce_ms),
      callback_press1(custom_press1),
      callback_press2(custom_press2),
      callback_press3(custom_press3),
      callback_hold1(custom_hold1),
      callback_hold2(custom_hold2),
      callback_hold3(custom_hold3)
    {}

    hold3Button(
      uint8_t pin,
      callbackVoid::callback_t custom_press1,
      callbackTime::callback_t custom_hold1,
      callbackTime::callback_t custom_hold2,
      callbackTime::callback_t custom_hold3,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      hold3ButtonGen(pin, debounce_ms),
      callback_press1(custom_press1),
      callback_press2(custom_press1),
      callback_press3(custom_press1),
      callback_hold1(custom_hold1),
      callback_hold2(custom_hold2),
      callback_hold3(custom_hold3)
    {}

    inline void runPress1() {callback_press1.execute();}
    inline void runPress2() {callback_press2.execute();}
    inline void runPress3() {callback_press3.execute();}
    inline void runHold1(uint32_t time) {callback_hold1.execute(time);}
    inline void runHold2(uint32_t time) {callback_hold2.execute(time);}
    inline void runHold3(uint32_t time) {callback_hold3.execute(time);}
};

#endif