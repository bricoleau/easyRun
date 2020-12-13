#ifndef pressButton_h
#define pressButton_h

#include "button.h"
#include "callbacks.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//pressButton for handling events :
//single click : short press / long press
//
//press2Button for handling events :
//single click : short press / long press
//double click : short press / long press
//
//press3Button for handling events :
//single click : short press / long press
//double click : short press / long press
//triple click : short press / long press
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class pressButtonData
{
  public :
    static const uint32_t DEFAULT_LONG_PRESS_TIME = 2000;

    pressButtonData(uint32_t long_press_ms = DEFAULT_LONG_PRESS_TIME) :
      long_press_time(long_press_ms),
      short_press(false)
    {}

  protected :
    uint32_t long_press_time;
    bool short_press;
};

class pressButtonGen : public hookedButton, public pressButtonData
{
  public :
    pressButtonGen(uint8_t pinNumber, uint32_t long_press_ms = DEFAULT_LONG_PRESS_TIME, uint8_t debounce = DEFAULT_DEBOUNCE_MS) :
      hookedButton(pinNumber, debounce),
      pressButtonData(long_press_ms)
    {}

    virtual void shortPress() = 0;
    virtual void longPress()  = 0;
  protected :
    void hook();
};

class pressButton : public pressButtonGen
{
  public :
    callbackVoid callback_short, callback_long;

    pressButton(
      uint8_t pin,
      callbackVoid::callback_t custom_short,
      callbackVoid::callback_t custom_long,
      uint32_t long_press_ms = DEFAULT_LONG_PRESS_TIME, 
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      pressButtonGen(pin, long_press_ms, debounce_ms),
      callback_short(custom_short),
      callback_long(custom_long)
    {}

    inline void shortPress() {callback_short.execute();}
    inline void longPress()  {callback_long.execute();}
};

class press2ButtonGen : public hooked2Button, public pressButtonData
{
  public :
    press2ButtonGen(uint8_t pinNumber, uint32_t long_press_ms = DEFAULT_LONG_PRESS_TIME, uint8_t debounce = DEFAULT_DEBOUNCE_MS) :
      hooked2Button(pinNumber, debounce),
      pressButtonData(long_press_ms)
    {}

    virtual void shortPress1() = 0;
    virtual void longPress1()  = 0;
    virtual void shortPress2() = 0;
    virtual void longPress2()  = 0;
  protected :
    void hook();
};

class press2Button : public press2ButtonGen
{
  public :
    callbackVoid callback_short1, callback_long1;
    callbackVoid callback_short2, callback_long2;

    press2Button(
      uint8_t pin,
      callbackVoid::callback_t custom_short1,
      callbackVoid::callback_t custom_long1,
      callbackVoid::callback_t custom_short2,
      callbackVoid::callback_t custom_long2,
      uint32_t long_press_ms = DEFAULT_LONG_PRESS_TIME, 
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      press2ButtonGen(pin, long_press_ms, debounce_ms),
      callback_short1(custom_short1),
      callback_long1(custom_long1),
      callback_short2(custom_short2),
      callback_long2(custom_long2)
    {}

    inline void shortPress1() {callback_short1.execute();}
    inline void longPress1()  {callback_long1.execute();}
    inline void shortPress2() {callback_short2.execute();}
    inline void longPress2()  {callback_long2.execute();}
};

class press3ButtonGen : public hooked3Button, public pressButtonData
{
  public :
    press3ButtonGen(uint8_t pinNumber, uint32_t long_press_ms = DEFAULT_LONG_PRESS_TIME, uint8_t debounce = DEFAULT_DEBOUNCE_MS) :
      hooked3Button(pinNumber, debounce),
      pressButtonData(long_press_ms)
    {}

    virtual void shortPress1() = 0;
    virtual void longPress1()  = 0;
    virtual void shortPress2() = 0;
    virtual void longPress2()  = 0;
    virtual void shortPress3() = 0;
    virtual void longPress3()  = 0;
  protected :
    void hook();
};

class press3Button : public press3ButtonGen
{
  public :
    callbackVoid callback_short1, callback_long1;
    callbackVoid callback_short2, callback_long2;
    callbackVoid callback_short3, callback_long3;

    press3Button(
      uint8_t pin,
      callbackVoid::callback_t custom_short1,
      callbackVoid::callback_t custom_long1,
      callbackVoid::callback_t custom_short2,
      callbackVoid::callback_t custom_long2,
      callbackVoid::callback_t custom_short3,
      callbackVoid::callback_t custom_long3,
      uint32_t long_press_ms = DEFAULT_LONG_PRESS_TIME, 
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      press3ButtonGen(pin, long_press_ms, debounce_ms),
      callback_short1(custom_short1),
      callback_long1(custom_long1),
      callback_short2(custom_short2),
      callback_long2(custom_long2),
      callback_short3(custom_short3),
      callback_long3(custom_long3)
    {}

    inline void shortPress1() {callback_short1.execute();}
    inline void longPress1()  {callback_long1.execute();}
    inline void shortPress2() {callback_short2.execute();}
    inline void longPress2()  {callback_long2.execute();}
    inline void shortPress3() {callback_short3.execute();}
    inline void longPress3()  {callback_long3.execute();}
};

#endif