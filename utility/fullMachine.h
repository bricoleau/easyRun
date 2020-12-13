#ifndef fullMachine_h
#define fullMachine_h

#include "stateMachine.h"

//Root template of any runable state machine
template<typename state_callback>
class fullMachineTemplate : public stateMachineTemplate<state_callback>
{
  public :
    typedef state_callback state_t;

  protected :
    state_t  _previous, _next;
    uint32_t _changeTime, _wait;
    bool     _first;

  public :
    fullMachineTemplate(state_t first_state) :
      stateMachineTemplate<state_callback>(first_state),
      _previous(NULL),
      _next(NULL),
      _changeTime(0),
      _wait(0),
      _first(true)
    {
    }

    void next(state_t next_state, uint32_t wait_ms)
    {
      _next = next_state;
      _changeTime = millis();
      _wait = wait_ms;
    }

    inline void next(state_t next_state) {next(next_state, 0);}

    inline void retry(uint32_t wait_ms = 0)   {next(stateMachineTemplate<state_callback>::_current, wait_ms);}
    inline void getBack(uint32_t wait_ms = 0) {next(_previous, wait_ms);}

    inline bool first()                         const {return _first;}
    inline bool previousStateIs(state_t state)  const {return state == _previous;}
    inline bool nextStateIs(state_t state)      const {return state == _next;}
    inline bool willChangeNextRun()             const {return _next != NULL;}

    //templates for derived classes
    template<typename T>
    inline void next(T next_state, uint32_t wait_ms=0) {next((state_t) next_state, wait_ms);}

    template<typename T>
    inline bool previousStateIs(T state) const {return previousStateIs((state_t)state);}

    template<typename T>
    inline bool nextStateIs(T state) const {return nextStateIs((state_t)state);}

  protected :
    void run()
    {
      if (_next == NULL || millis() - _changeTime >= _wait)
      {
        if (_next != NULL)
        {
          _previous = stateMachineTemplate<state_callback>::_current;
          stateMachineTemplate<state_callback>::_current = _next;
          _next = NULL;
          _first = true;
          stateMachineTemplate<state_callback>::_startTime = millis();
        }
        if (stateMachineTemplate<state_callback>::_current != NULL)
        {
          runCurrent();
        }
        _first = false;
      }
    }
    virtual void runCurrent() = 0; //depending on state_t
};

//A basic state machine class working with user-defined functions
//Each state is a pointer to an external void function()
class fullMachine : public fullMachineTemplate<void (*)()>
{
  public :
    fullMachine(state_t first_state = NULL) : fullMachineTemplate(first_state) {}

  protected :
    inline void runCurrent() {_current();}
};

//An abstract for state machine classes
//Each state is a pointer to a void method() within any class derived from fullMachineGen
class fullMachineGen : public fullMachineTemplate<void (fullMachineGen::*)()>
{
  public :
    fullMachineGen() : fullMachineTemplate(&fullMachineGen::init) {}

  protected :
    void runCurrent() {(this->*_current)();}

    //init() is the first state and must be defined within each derived class
    virtual void init() = 0;
};

#endif

