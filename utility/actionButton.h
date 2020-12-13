#ifndef actionButton_h
#define actionButton_h

#include "button.h"
#include "callbacks.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//actionButton for handling events :
//single click : press / release
//
//action2Button for handling events :
//single click : press1 / release1
//double click : press2 / release2
//
//action3Button for handling events :
//single click : press1 / release1
//double click : press2 / release2
//triple click : press3 / release3
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class actionButtonGen : public hookedButton
{
  public :
    actionButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hookedButton(pinNumber, debounce) {}

    virtual void runPress() = 0;
    virtual void runRelease() = 0;

  protected :
    void hook();
};

class actionButton : public actionButtonGen
{
  public :
    callbackVoid callback_press, callback_release;

    actionButton(
      uint8_t pin,
      callbackVoid::callback_t custom_pressed,
      callbackVoid::callback_t custom_released,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      actionButtonGen(pin, debounce_ms),
      callback_press(custom_pressed),
      callback_release(custom_released)
    {}

    inline void runPress() {callback_press.execute();}
    inline void runRelease() {callback_release.execute();}
};

class action2ButtonGen : public hooked2Button
{
  public :
    action2ButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hooked2Button(pinNumber, debounce) {}

    virtual void runPress1() = 0;
    virtual void runRelease1() = 0;
    virtual void runPress2() = 0;
    virtual void runRelease2() = 0;
  protected :
    void hook();
};

class action2Button : public action2ButtonGen
{
  public :
    callbackVoid callback_press1, callback_release1;
    callbackVoid callback_press2, callback_release2;

    action2Button(
      uint8_t pin,
      callbackVoid::callback_t custom_pressed1,
      callbackVoid::callback_t custom_released1,
      callbackVoid::callback_t custom_pressed2,
      callbackVoid::callback_t custom_released2,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      action2ButtonGen(pin, debounce_ms),
      callback_press1(custom_pressed1),
      callback_release1(custom_released1),
      callback_press2(custom_pressed2),
      callback_release2(custom_released2)
    {}

    inline void runPress1()   {callback_press1.execute();}
    inline void runRelease1() {callback_release1.execute();}
    inline void runPress2()   {callback_press2.execute();}
    inline void runRelease2() {callback_release2.execute();}
};

class action3ButtonGen : public hooked3Button
{
  public :
    action3ButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hooked3Button(pinNumber, debounce) {}

    virtual void runPress1() = 0;
    virtual void runRelease1() = 0;
    virtual void runPress2() = 0;
    virtual void runRelease2() = 0;
    virtual void runPress3() = 0;
    virtual void runRelease3() = 0;
  protected :
    void hook();
};

class action3Button : public action3ButtonGen
{
  public :
    callbackVoid callback_press1, callback_release1;
    callbackVoid callback_press2, callback_release2;
    callbackVoid callback_press3, callback_release3;

    action3Button(
      uint8_t pin,
      callbackVoid::callback_t custom_pressed1,
      callbackVoid::callback_t custom_released1,
      callbackVoid::callback_t custom_pressed2,
      callbackVoid::callback_t custom_released2,
      callbackVoid::callback_t custom_pressed3,
      callbackVoid::callback_t custom_released3,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      action3ButtonGen(pin, debounce_ms),
      callback_press1(custom_pressed1),
      callback_release1(custom_released1),
      callback_press2(custom_pressed2),
      callback_release2(custom_released2),
      callback_press3(custom_pressed3),
      callback_release3(custom_released3)
    {}

    inline void runPress1()   {callback_press1.execute();}
    inline void runRelease1() {callback_release1.execute();}
    inline void runPress2()   {callback_press2.execute();}
    inline void runRelease2() {callback_release2.execute();}
    inline void runPress3()   {callback_press3.execute();}
    inline void runRelease3() {callback_release3.execute();}
};

#endif