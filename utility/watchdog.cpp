#include "watchdog.h"


watchdog::watchdog(uint32_t cycle_ms)
{
  set(cycle_ms);
}

void watchdog::set(uint32_t cycle_ms)
{
  disable();
  boardSet(cycle_ms);
  enable();
}

void watchdog::enable()
{
  boardEnable();
  _active = true;
}

void watchdog::disable()
{
  boardDisable();
  _active = false;
}

void watchdog::run()
{
  if (_active) boardReset();
}

#if defined(AVR)  //arduino AVR boards : uno, nano, mega, pro mini...
#include "avr/wdt.h"

void watchdog::boardSet(uint32_t cycle_ms)
{
  if      (cycle_ms <=   15) _cycle =   15;
  else if (cycle_ms <=   30) _cycle =   30;
  else if (cycle_ms <=   60) _cycle =   60;
  else if (cycle_ms <=  120) _cycle =  120;
  else if (cycle_ms <=  250) _cycle =  250;
  else if (cycle_ms <=  500) _cycle =  500;
  else if (cycle_ms <= 1000) _cycle = 1000;
  else if (cycle_ms <= 2000) _cycle = 2000;
  else if (cycle_ms <= 4000) _cycle = 4000;
  else                       _cycle = 8000;
}

void watchdog::boardEnable()
{
  uint8_t wdto;
  switch (_cycle)
  {
    case   15 : wdto = WDTO_15MS; break;
    case   30 : wdto = WDTO_30MS; break;
    case   60 : wdto = WDTO_60MS; break;
    case  120 : wdto = WDTO_120MS; break;
    case  250 : wdto = WDTO_250MS; break;
    case  500 : wdto = WDTO_500MS; break;
    case 1000 : wdto = WDTO_1S; break;
    case 2000 : wdto = WDTO_2S; break;
    case 4000 : wdto = WDTO_4S; break;
    default   : wdto = WDTO_8S;
  }
  wdt_enable(wdto);
}

void watchdog::boardDisable()
{
  wdt_disable();
}

void watchdog::boardReset()
{
  wdt_reset();
}

#else  //other cards : not handled

void watchdog::boardSet(uint32_t cycle_ms) {_cycle = cycle_ms;}
void watchdog::boardEnable() {}
void watchdog::boardDisable() {}
void watchdog::boardReset() {}

#endif

