#ifndef button_h
#define button_h

#include "runable.h"

//Wire : pin---BTN---GND

//Comment this line if you need to have multiple buttons with different debounce time
#define UNIQUE_DEBOUNCE_TIME

class button : public runable
{
  public :
    static const uint8_t DEFAULT_DEBOUNCE_MS = 20;

    button(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS);

    virtual bool pressed() const;
    virtual bool changed() const;
    virtual uint32_t time() const;

    inline uint8_t pinNumber()             const {return pin;}
    inline bool released()                 const {return !pressed();}
    inline bool newPress()                 const {return changed() && pressed();} 
    inline bool newRelease()               const {return changed() && released();} 
    inline uint32_t pressTime()            const {return pressed() ? time() : 0;}
    inline uint32_t releaseTime()          const {return pressed() ? 0 : time();}
    inline bool pressedFor(uint32_t time)  const {return pressTime() >= time;}
    inline bool releasedFor(uint32_t time) const {return releaseTime() >= time;}

    operator bool() {return newPress();}

    #ifdef UNIQUE_DEBOUNCE_TIME
        static uint8_t debounce_ms;
    #else
        uint8_t debounce_ms;
    #endif

  protected :
    uint8_t pin;
    inline void init()  const {pinMode(pin, INPUT_PULLUP);}
    inline bool isLOW() const {return digitalRead(pin) == LOW;} 

    uint8_t status;
    uint32_t millis_changing, millis_changed;

    bool update(uint32_t now);
    virtual void run() {update(millis());}
};


//an extended class to multiple clicks
class mButton : public button
{
  public :
    static const uint32_t MAX_TIME_BETWEEN_CLICKS = 500; //milliseconds
    uint8_t clicks, maxClicks;

    mButton(uint8_t pinNumber, uint8_t maxClicks=255, uint8_t debounce = DEFAULT_DEBOUNCE_MS);

    bool pressed() const;
    bool changed() const;
    uint32_t time() const;

  protected :
    uint32_t millis_click, millis_mChanged;

    bool mUpdate(uint32_t now);
    virtual void run() {mUpdate(millis());}
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//generic classes for adding callbacks on button events

//void hook(); // must be defined in each derived class

//single click
class hookedButton : public button
{
  public :
    hookedButton(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : button(pinNumber, debounce) {}

  protected :
    virtual void hook() = 0;
    void run()
    {
      update(millis());
      hook();
    }
};

//multi clicks
template<uint8_t maxiClicks>
class hookedmButton : public mButton
{
  public :
    hookedmButton(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : mButton(pinNumber, maxiClicks, debounce) {}

  protected :
    virtual void hook() = 0;
    void run()
    {
      mUpdate(millis());
      hook();
    }
};

//double click
class hooked2Button : public hookedmButton<2>
{
  public :
    hooked2Button(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hookedmButton(pinNumber, debounce) {}
};

//triple click
class hooked3Button : public hookedmButton<3>
{
  public :
    hooked3Button(uint8_t pinNumber, uint8_t debounce = DEFAULT_DEBOUNCE_MS) : hookedmButton(pinNumber, debounce) {}
};

#endif