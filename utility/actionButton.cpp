#include "actionButton.h"

void actionButtonGen::hook()
{
  if (changed())
  {
    if (pressed())
    {
      runPress();
    }
    else
    {
      runRelease();
    } 
  }
}

void action2ButtonGen::hook()
{
  if (changed())
  {
    if (pressed())
    {
      switch (clicks)
      {
        case 1 : runPress1(); break;
        case 2 : runPress2();
      }
    }
    else
    {
      switch (clicks)
      {
        case 1 : runRelease1(); break;
        case 2 : runRelease2();
      }
    } 
  }
}

void action3ButtonGen::hook()
{
  if (changed())
  {
    if (pressed())
    {
      switch (clicks)
      {
        case 1 : runPress1(); break;
        case 2 : runPress2(); break;
        case 3 : runPress3();
      }
    }
    else
    {
      switch (clicks)
      {
        case 1 : runRelease1(); break;
        case 2 : runRelease2(); break;
        case 3 : runRelease3();
      }
    } 
  }
}

