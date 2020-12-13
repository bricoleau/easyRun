#ifndef loopMeter_h
#define loopMeter_h

#include "runable.h"

class loopMeter : public runable
{
  private :
    static const uint32_t DEFAULT_PERIOD = 10000;
    uint32_t statsPeriod;
    uint32_t loopCount;
    uint32_t startTime, lastTime, minTime, maxTime;
    void run();

  public :
    loopMeter(uint32_t period = DEFAULT_PERIOD);
    void begin(uint32_t period = DEFAULT_PERIOD); //Calling begin() from setup() is optional

    inline void set(uint32_t period) {statsPeriod = period;}
    inline uint32_t count() const {return loopCount;}
};

#endif
