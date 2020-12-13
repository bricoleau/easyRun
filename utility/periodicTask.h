#ifndef periodicTask_h
#define periodicTask_h

#include "runable.h"
#include "callbacks.h"

class periodicTaskGen : public runable
{
  public :
    uint32_t cycle; //milliseconds

    periodicTaskGen(uint32_t cycle_ms = 0) :
      cycle(cycle_ms),
      millis_last_run(0 - cycle_ms)
    {}

    virtual void periodicRun() = 0;

  protected :
    uint32_t millis_last_run;
    void run();
};

class periodicTask : public periodicTaskGen
{
  public :
    callbackVoid callback;
    
    periodicTask(
      callbackVoid::callback_t custom_callback = NULL,
      uint32_t cycle_ms = 0
    ) :
      periodicTaskGen(cycle_ms),
      callback(custom_callback)
    {}

    inline void periodicRun() {callback.execute();}

    inline operator bool() {return callback.isSet();}
    periodicTask& operator =(callbackVoid::callback_t custom_callback) {callback.set(custom_callback); return *this;}
};

#endif