#ifndef clickButton_h
#define clickButton_h

#include "button.h"
#include "callbacks.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//clickButton for handling events :
//single click
//
//click2Button for handling events :
//single click
//double click
//
//click3Button for handling events :
//single click
//double click
//triple click
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class clickButtonGen : public hookedButton
{
  public :
    clickButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hookedButton(pinNumber, debounce) {}

    virtual void runClick() = 0;
  protected :
    void hook();
};

class clickButton : public clickButtonGen
{
  public :
    callbackVoid callback_click;

    clickButton(
      uint8_t pin,
      callbackVoid::callback_t custom_clicked,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      clickButtonGen(pin, debounce_ms),
      callback_click(custom_clicked)
    {}

    inline void runClick() {callback_click.execute();}
};

class click2ButtonGen : public hooked2Button
{
  public :
    click2ButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hooked2Button(pinNumber, debounce) {}

    virtual void runClick1() = 0;
    virtual void runClick2() = 0;
  protected :
    void hook();
};

class click2Button : public click2ButtonGen
{
  public :
    callbackVoid callback_click1, callback_click2;

    click2Button(
      uint8_t pin,
      callbackVoid::callback_t custom_clicked1,
      callbackVoid::callback_t custom_clicked2,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      click2ButtonGen(pin, debounce_ms),
      callback_click1(custom_clicked1),
      callback_click2(custom_clicked2)
    {}

    inline void runClick1()   {callback_click1.execute();}
    inline void runClick2()   {callback_click2.execute();}
};

class click3ButtonGen : public hooked3Button
{
  public :
    click3ButtonGen(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hooked3Button(pinNumber, debounce) {}

    virtual void runClick1() = 0;
    virtual void runClick2() = 0;
    virtual void runClick3() = 0;
  protected :
    void hook();
};

class click3Button : public click3ButtonGen
{
  public :
    callbackVoid callback_click1, callback_click2, callback_click3;

    click3Button(
      uint8_t pin,
      callbackVoid::callback_t custom_clicked1,
      callbackVoid::callback_t custom_clicked2,
      callbackVoid::callback_t custom_clicked3,
      uint8_t debounce_ms = DEFAULT_DEBOUNCE_MS
    ) :
      click3ButtonGen(pin, debounce_ms),
      callback_click1(custom_clicked1),
      callback_click2(custom_clicked2),
      callback_click3(custom_clicked3)
    {}

    inline void runClick1()   {callback_click1.execute();}
    inline void runClick2()   {callback_click2.execute();}
    inline void runClick3()   {callback_click3.execute();}
};

#endif