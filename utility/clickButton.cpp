#include "clickButton.h"

void clickButtonGen::hook()
{
  if (newPress())
  {
    runClick();
  }
}

void click2ButtonGen::hook()
{
  if (newPress())
  {
    switch (clicks)
    {
      case 1 : runClick1(); break;
      case 2 : runClick2();
    }
  }
}

void click3ButtonGen::hook()
{
  if (newPress())
  {
    switch (clicks)
    {
      case 1 : runClick1(); break;
      case 2 : runClick2(); break;
      case 3 : runClick3();
    }
  }
}

