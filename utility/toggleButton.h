#ifndef toggleButton_h
#define toggleButton_h

#include "clickButton.h"
#include "callbacks.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//toggleButton for handling events :
//  single click : toggle on/off

//toggle2Button for handling events :
//  single click : toggle on1/off1
//  double click : toggle on2/off2

//toggle3Button for handling events :
//  single click : toggle on1/off1
//  double click : toggle on2/off2
//  triple click : toggle on3/off3

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class togglerGen
{
  protected :
    bool activated;
    inline bool flip() {return activated = !activated;}

    virtual void switchOn() = 0;
    virtual void switchOff() = 0;

  public :
    togglerGen() : activated(false) {}

    inline void toggle() {if (flip()) switchOn(); else switchOff();}
};

class toggler : public togglerGen
{
  public :
    callbackVoid on, off;

    toggler(
      callbackVoid::callback_t custom_on,
      callbackVoid::callback_t custom_off
    ) :
      on(custom_on),
      off(custom_off)
    {}

  protected :
    void switchOn()  {on.execute();}
    void switchOff() {off.execute();}
};

class toggleButton : public clickButtonGen
{
  public :
    toggler t1;

    toggleButton(
      uint8_t pin,
      callbackVoid::callback_t custom_on,
      callbackVoid::callback_t custom_off,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      clickButtonGen(pin, debounce_ms),
      t1(custom_on, custom_off)
    {}

    inline void runClick() {t1.toggle();}
};

class toggle2Button : public click2ButtonGen
{
  public :
    toggler t1, t2;

    toggle2Button(
      uint8_t pin,
      callbackVoid::callback_t custom_on1, callbackVoid::callback_t custom_off1,
      callbackVoid::callback_t custom_on2, callbackVoid::callback_t custom_off2,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      click2ButtonGen(pin, debounce_ms),
      t1(custom_on1, custom_off1),
      t2(custom_on2, custom_off2)
    {}

    inline void runClick1() {t1.toggle();}
    inline void runClick2() {t2.toggle();}
};

class toggle3Button : public click3ButtonGen
{
  public :
    toggler t1, t2, t3;

    toggle3Button(
      uint8_t pin,
      callbackVoid::callback_t custom_on1, callbackVoid::callback_t custom_off1,
      callbackVoid::callback_t custom_on2, callbackVoid::callback_t custom_off2,
      callbackVoid::callback_t custom_on3, callbackVoid::callback_t custom_off3,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      click3ButtonGen(pin, debounce_ms),
      t1(custom_on1, custom_off1),
      t2(custom_on2, custom_off2),
      t3(custom_on3, custom_off3)
    {}

    inline void runClick1() {t1.toggle();}
    inline void runClick2() {t2.toggle();}
    inline void runClick3() {t3.toggle();}
};

#endif