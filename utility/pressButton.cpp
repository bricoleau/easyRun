#include "pressButton.h"

void pressButtonGen::hook()
{
  if (newPress())
  {
    short_press = true;
  }
  if (short_press)
  {
    if (newRelease())
    {
      shortPress();
      short_press = false;
    }
    else if (pressedFor(long_press_time))
    {
      short_press = false;
      longPress();
    }
  }
}

void press2ButtonGen::hook()
{
  if (newPress())
  {
    short_press = true;
  }
  if (short_press)
  {
    if (newRelease())
    {
      switch (clicks)
      {
        case 1 : shortPress1(); break;
        case 2 : shortPress2();
      }
      short_press = false;
    }
    else if (pressedFor(long_press_time))
    {
      short_press = false;
      switch (clicks)
      {
        case 1 : longPress1(); break;
        case 2 : longPress2();
      }
    }
  }
}

void press3ButtonGen::hook()
{
  if (newPress())
  {
    short_press = true;
  }
  if (short_press)
  {
    if (newRelease())
    {
      switch (clicks)
      {
        case 1 : shortPress1(); break;
        case 2 : shortPress2(); break;
        case 3 : shortPress3();
      }
      short_press = false;
    }
    else if (pressedFor(long_press_time))
    {
      short_press = false;
      switch (clicks)
      {
        case 1 : longPress1(); break;
        case 2 : longPress2(); break;
        case 3 : longPress3();
      }
    }
  }
}

