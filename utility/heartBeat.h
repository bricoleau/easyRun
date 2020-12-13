#ifndef heartBeat_h
#define heartBeat_h

#include "runable.h"
#include "easyLed.h"

class heartBeat : public runable
{
  public :
    easyLed led;
    static const uint32_t DEFAULT_CYCLE = 2000;
    heartBeat(uint32_t cycle_ms = DEFAULT_CYCLE);//heartBeat on builtin led
    heartBeat(uint32_t cycle_ms, uint8_t pin, bool light_on_LOW = false);

    //stop/start pulse on led
    void stop();
    void start();

    static const uint32_t ERROR_FLASH = 200;
    static const uint32_t ERROR_AUTO_RESET = 30000;
    void raiseError(uint8_t errorCode);
    inline void resetError() {raiseError(0);}
    inline uint8_t errorCode() const {return err;}
    inline bool error() const {return errorCode() != 0;}
  
  private :
    bool beat;
    uint8_t err;
    uint32_t errTime, cycle;
  
    void run();
};

#endif

