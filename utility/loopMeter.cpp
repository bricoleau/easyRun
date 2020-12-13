#include "loopMeter.h"
#include "easylog.h"

loopMeter::loopMeter(uint32_t period)
{
  loopCount = 0;
  set(period);
}

void loopMeter::begin(uint32_t period)
{
  set(period);
  setLastRunable();
}

void loopMeter::run()
{
  uint32_t now = millis();

  if (loopCount == 0)
  {
    startTime = now;
    lastTime  = now;
    loopCount = 1;
  }
  else
  {
    uint32_t fromStart = now - startTime;
    uint32_t fromLast  = now - lastTime;

    if (loopCount == 1 || fromLast < minTime)
    {
      minTime = fromLast;
    }
    if (loopCount == 1 || fromLast > maxTime)
    {
      maxTime = fromLast;
    }
    lastTime  = now;

    if (fromStart >= statsPeriod)
    {
      easyLog.print(F("loopMeter: min="));
      easyLog.print(minTime);
      easyLog.print(F("ms avg="));
      easyLog.print(fromStart/loopCount);
      easyLog.print(F("ms max="));
      easyLog.print(maxTime);
      easyLog.print(F("ms => "));
      easyLog.print(loopCount / ((fromStart+500)/1000));
      easyLog.print(F(" loops per sec ("));
      easyLog.print(runable::nbRunable());
      easyLog.println(F(" easyRun items)"));
      loopCount = 0;
      startTime = now;
    }

    loopCount++;
  }
}