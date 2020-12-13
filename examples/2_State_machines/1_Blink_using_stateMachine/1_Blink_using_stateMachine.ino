#include "easyRun.h"

/* state machine demo

A state machine allows to run one state_function(), within each easyRun(), depending on current state.

You should mainly use :
.next(state_function)
.time() or .timeIsOver(nnn)

see stateMachine.h for complete list of properties and methods 
*/

//Declare all functions that are to be considered as a state of the machine
void ledInit();
void ledHigh();
void ledLow();
stateMachine sm(ledInit); //ledInit is the very first state of the machine

void ledInit()
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  sm.next(ledHigh);//change state to ledHigh
}

void ledHigh()
{
  if (sm.time() >= 1000) //test time in current state
  {
    digitalWrite(LED_BUILTIN, LOW);
    sm.next(ledLow);
  }
}

void ledLow()
{
  if (sm.timeIsOver(1000)) //another way to test time in current state
  {
    digitalWrite(LED_BUILTIN, HIGH);
    sm.next(ledHigh);
  }
}

void setup()
{
}

void loop()
{
  easyRun();
}

