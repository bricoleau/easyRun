#include "button.h"

#ifdef UNIQUE_DEBOUNCE_TIME
  uint8_t button::debounce_ms = button::DEFAULT_DEBOUNCE_MS;
#endif

button::button(uint8_t pinNumber, uint8_t debounce) :
  pin(pinNumber),
  status(0),
  millis_changing(0),
  millis_changed(0)
{
  debounce_ms = debounce;
  init();
}

bool button::pressed()  const {return ((status & 0b00000001) != 0);}
bool button::changed()  const {return ((status & 0b00000010) != 0);}
uint32_t button::time() const {return millis() - millis_changed;}

bool button::update(uint32_t now)
{
  status &= 0b11111101; //reset changed

  bool pressed  = ((status & 0b00000001) != 0);
  bool changing = ((status & 0b00000100) != 0);

  bool instantPressed = isLOW();

  if (changing) //a changing state has been previously detected
  {
    if (instantPressed == pressed) //not confirmed
    {
      millis_changing = now;
      status &= 0b11111011; //reset changing
    }
    else if (now - millis_changing >= debounce_ms) //confirmed
    {
      millis_changed = now;
      millis_changing = now;
      status ^= 0b00000001; //toggle pressed
      status |= 0b00000010; //set changed
      status &= 0b11111011; //reset changing
    }
  }
  else
  {
    millis_changing = now;
    if (instantPressed != pressed) //a new state is detected
    {
      status |= 0b00000100; //set changing
    }
  }

  return ((status & 0b00000010) != 0); //return changed
}

mButton::mButton(uint8_t pinNumber, uint8_t maxClicks, uint8_t debounce) :
  button(pinNumber, debounce),
  clicks(0),
  maxClicks(maxClicks),
  millis_click(0),
  millis_mChanged(0)
{
}

bool mButton::pressed()  const {return ((status & 0b00001000) != 0);}
bool mButton::changed()  const {return ((status & 0b00010000) != 0);}
uint32_t mButton::time() const {return millis() - millis_mChanged;}

bool mButton::mUpdate(uint32_t now)
{
  //reinit after mChanged
  bool mChanged = ((status & 0b00010000) != 0);
  if (mChanged)
  {
    bool mReleased = ((status & 0b00001000) == 0);
    if (mReleased)
    {
      status &= 0b00000111; //reset all flags
      clicks = 0;
    }
    else
    {
      status &= 0b11101111; //reset mChanged
    }  
    mChanged = false;
  }
  
  //a release might be buffered
  bool noUpdate = ((status & 0b01000000) != 0);
  if (noUpdate)
  {
    millis_mChanged = now;
    status &= 0b11110111; //set mReleased
    status |= 0b00010000; //set mChanged
    mChanged = true; 
    return mChanged;
  }

  //main part
  bool changed = update(now);
  bool pressed  = ((status & 0b00000001) != 0);
  if (changed && pressed)
  {
    clicks++;
    millis_click = now;
  }
  else if (clicks > 0)
  {
    bool mFirst = ((status & 0b00100000) == 0);
    if (mFirst)
    {
      if (clicks == maxClicks || millis() - millis_click >= MAX_TIME_BETWEEN_CLICKS)
      {
        if (pressed)
        {
          status |= 0b00111000; //set mPressed & mChanged & !mFirst
        }
        else
        {
          //release is buffered for next run
          status |= 0b01011000; //set mPressed & mChanged & noUpdate
        }
        millis_mChanged = now;
        mChanged = true;
      }
    }
    else if (!pressed)
    {
      millis_mChanged = now;  
      status |= 0b00010000; //set mChanged
      status &= 0b11110111; //set mReleased
      mChanged = true;
    }
  }
  return mChanged;
}

