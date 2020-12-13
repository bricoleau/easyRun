#include "heartBeat.h"
#include "easyLog.h"

heartBeat::heartBeat(uint32_t cycle_ms) :
  led(LED_BUILTIN, LED_BUILTIN_LIGHT_ON_LOW),
  beat(true),
  err(0),
  errTime(0),
  cycle(cycle_ms)
{
}

heartBeat::heartBeat(uint32_t cycle_ms, uint8_t pin, bool light_on_LOW) :
  led(pin,light_on_LOW),
  beat(true),
  err(0),
  errTime(0),
  cycle(cycle_ms)
{
}

void heartBeat::stop()
{
  beat = false;
  if (err == 0)
  {
    led.off();
  }
}

void heartBeat::start()
{
  beat = true;
}

void heartBeat::raiseError(uint8_t errorCode)
{
  errTime = millis();
	if (err != errorCode)
	{
		err = errorCode;
		if (err == 0)
		{
			easyDebug.println(F("heartBeat: idle"));
      if (!beat)
      {
        led.off();
      }
		}
		else
		{
			easyDebug.print(F("heartBeat: raising error code "));
			easyDebug.println(err);
		}
	}
}

void heartBeat::run()
{
  if (err != 0)
  {
    uint32_t panicTime = millis() - errTime;
    uint32_t flashing = (err * 2 - 1) * ERROR_FLASH;
    uint32_t cycle_ms = panicTime % (flashing + 1000);
    if (cycle_ms < flashing && ((cycle_ms / ERROR_FLASH)&1) == 0)
    {
      led.on();
    }
    else
    {
      led.off();
    }
    if (panicTime >= ERROR_AUTO_RESET)
    {
      resetError();
    }
  }
  else if (beat)
  {
    uint32_t value = millis() % cycle;
    if (value > cycle / 2)
    {
      value = cycle - value;
    }
    value = (value << 9) / cycle;
    if (led.hasPWM())
    {
      value = (value * value) >> 8; 
    }
    led.set(value & 0xff);
  }
}