#include "runMeter.h"
#include "easylog.h"

runMeter::runMeter(runable &item, const char *name, uint32_t period) :
  monitored(&item),
  init(true),
  traceName(name),
  statsPeriod(period)
{}

void runMeter::run()
{
  uint32_t now = millis();
  if (init)
  {
    init = false;
    start.setBeforeRunable(*monitored);
    this->setAfterRunable(*monitored);
    nb = 0;
    sumTime = 0;
    startTime = now;
  }
  else
  {
    uint32_t time = now - start.time;
    sumTime += time;
    nb++;
    if (nb == 1 || time < minTime) minTime = time;
    if (nb == 1 || time > maxTime) maxTime = time;
    if (now - startTime >= statsPeriod)
    {
      easyLog.print(F("runMeter "));
      easyLog.print(traceName);
      easyLog.print(F(": nb="));
      easyLog.print(nb);
      easyLog.print(F(" min="));
      easyLog.print(minTime);
      easyLog.print(F("ms avg="));
      easyLog.print(sumTime/nb);
      easyLog.print(F("ms max="));
      easyLog.print(maxTime);
      easyLog.println(F("ms"));
      nb = 0;
      sumTime = 0;
      startTime = now;
    }
  }  
}