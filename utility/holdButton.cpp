#include "holdButton.h"

void holdButtonGen::hook()
{
  if (pressed())
  {
    if (changed())
    {
      runPress();
    }
    runHold(time());
  }
}

void hold2ButtonGen::hook()
{
  if (pressed())
  {
    if (changed())
    {
      switch (clicks)
      {
        case 1 : runPress1(); break;
        case 2 : runPress2();
      }
    }
    switch (clicks)
    {
      case 1 : runHold1(time()); break;
      case 2 : runHold2(time());
    }
  }
}

void hold3ButtonGen::hook()
{
  if (pressed())
  {
    if (changed())
    {
      switch (clicks)
      {
        case 1 : runPress1(); break;
        case 2 : runPress2(); break;
        case 3 : runPress3();
      }
    }
    switch (clicks)
    {
      case 1 : runHold1(time()); break;
      case 2 : runHold2(time()); break;
      case 3 : runHold3(time());
    }
  }
}

