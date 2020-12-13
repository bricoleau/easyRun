#ifndef watchdog_h
#define watchdog_h

#include "runable.h"

class watchdog : public runable
{
  public :
    static const uint32_t DEFAULT_CYCLE = 4000; //milliseconds
    watchdog(uint32_t cycle_ms = DEFAULT_CYCLE);

    void set(uint32_t cycle_ms);
    void disable();
    void enable();

    inline uint32_t cycle() const {return _cycle;}
    inline bool active() const {return _active;}
    inline operator bool() {return active();}

  private :
    bool _active;
    uint32_t _cycle;
    void run();

    void boardSet(uint32_t cycle_ms);
    void boardEnable();
    void boardDisable();
    void boardReset();
};

#endif