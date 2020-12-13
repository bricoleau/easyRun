#ifndef asyncTask_h
#define asyncTask_h

#include "runable.h"
#include "callbacks.h"

//Root template of any asyncTask class
template<typename async_callback>
class asyncTaskTemplate : public runable
{
  public :
    typedef async_callback target_t;

  protected :
    target_t _target;
    uint32_t _millis_ref, _delay_ms;

  public :
    asyncTaskTemplate() : _delay_ms(0) {}

    virtual void unset() = 0;
    virtual bool isSet() const = 0;
    virtual void execute() = 0;

    void setGen(target_t target, uint32_t delay_ms)
    {
      _target = target;
      _millis_ref = millis();
      _delay_ms = delay_ms;
    }

    uint32_t timeLeft() const
    {
      uint32_t left = 0;
      if (isSet())
      {
        uint32_t passed = millis() - _millis_ref;
        if (passed < _delay_ms)
        {
          left = _delay_ms - passed;
        }
      }
      return left;
    }

    inline operator bool() {return isSet();}

  protected :
    void run()
    {
      if (isSet() && timeLeft() == 0)
      {
        execute();
      }
    }
};

//class working with user-defined functions
class asyncTask : public asyncTaskTemplate<callbackVoid>
{
  public :
    inline void set(callbackVoid::callback_t custom_callback, uint32_t delay_ms) {setGen(callbackVoid(custom_callback), delay_ms);}
    inline void set(callbackVoid::callback_t custom_callback) {set(custom_callback, _delay_ms);}
    inline void unset() {_target.unset();}
    inline bool isSet() const {return _target.isSet();}
    void execute();
};

//Abstract for asyncTask classes
//Allowed targets are void methods() defined within any class derived from asyncTaskGen
class asyncTaskGen : public asyncTaskTemplate<void (asyncTaskGen::*)()>
{
  public :
    asyncTaskGen() {_target = NULL;}

    inline void set(target_t target, uint32_t delay_ms) {setGen(target, delay_ms);}
    inline void unset() {_target = NULL;}
    inline bool isSet() const {return _target != NULL;}
    void execute();

    //templates for derived classes
    template<typename T>
    inline void set(T target, uint32_t delay_ms) {set((target_t)target, delay_ms);}
    template<typename T>
    inline void set(T target) {set((target_t)target, _delay_ms);}
};

#endif