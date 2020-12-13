#ifndef stateMachine_h
#define stateMachine_h

#include "runable.h"

//Root template of any runable state machine
template<typename state_callback>
class stateMachineTemplate : public runable
{
  public :
    typedef state_callback state_t;

  protected :
    state_t  _current;
    uint32_t _startTime;

  public :
    stateMachineTemplate(state_t first_state) :
      _current(first_state),
      _startTime(0)
    {
    }

    void next(state_t next_state)
    {
      _current = next_state;
      _startTime = millis();
    }

    inline bool currentStateIs(state_t state)   const {return state == _current;}
    inline uint32_t time()                      const {return millis() - _startTime;}    
    inline bool timeIsOver(uint32_t timeOut_ms) const {return time() >= timeOut_ms;}

    //templates for derived classes
    template<typename T>
    inline void next(T next_state) {next((state_t) next_state);}

    template<typename T>
    inline bool currentStateIs(T state) const {return currentStateIs((state_t)state);}

  protected :
    virtual void runCurrent() = 0; //depending on state_t
    virtual void run()
    {
      if (_current != NULL)
      {
        runCurrent();
      }
    }
};

//A basic state machine class working with user-defined functions
//Each state is a pointer to an external void function()
class stateMachine : public stateMachineTemplate<void (*)()>
{
  public :
    stateMachine(state_t first_state = NULL) : stateMachineTemplate(first_state) {}

  protected :
    inline void runCurrent() {_current();}
};

//An abstract for state machine classes
//Each state is a pointer to a void method() within any class derived from stateMachineGen
class stateMachineGen : public stateMachineTemplate<void (stateMachineGen::*)()>
{
  public :
    stateMachineGen() : stateMachineTemplate(&stateMachineGen::init) {}

  protected :
    void runCurrent() {(this->*_current)();}

    //init() is the first state and must be defined within each derived class
    virtual void init() = 0;
};

#endif

