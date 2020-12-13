#include "periodicTask.h"

void periodicTaskGen::run()
{
  if (millis() - millis_last_run >= cycle)
  {
    millis_last_run += cycle;
    periodicRun();
    if (millis() - millis_last_run >= cycle)
    {
      //overflow : resync to current time
      millis_last_run = millis();
    }
  }
}