#ifndef runMeter_h
#define runMeter_h

#include "runable.h"

class runTimer : public runable
{
  public :
    uint32_t time;

  private :
    void run() {time = millis();}
};

class runMeter : public runable
{
  public :
    static const uint32_t DEFAULT_PERIOD = 10000; //milliseconds
    runMeter(runable &item, const char *name, uint32_t period = DEFAULT_PERIOD);

  private :
    runable *monitored;
    runTimer start;
    bool init;
    const char* traceName;
    uint32_t nb, startTime, minTime, maxTime, sumTime, statsPeriod;
    void run();
};

#endif