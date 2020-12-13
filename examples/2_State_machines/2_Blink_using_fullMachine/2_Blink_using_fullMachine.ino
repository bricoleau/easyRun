#include "easyRun.h"

/* full state machine demo

A fullMachine is a stateMachine with more properties & methods, increasing ram usage

Main new properties :
.first()                    //returns true if state_function() is ran for the first time after changing state, false otherwise
.next(state_function, time) //fullMachine will freeze for time and then switch to a new state 
.retry(time)                //same as next(currentState, time).
.getBack()                  //returns to previous state

see fullMachine.h for complete list of properties and methods 
*/

//Declare all functions that are to be considered as a state of the machine
void ledInit();
void ledHigh();
void ledLow();
fullMachine sm(ledInit);

void ledInit()
{
  Serial.println("init");
  pinMode(LED_BUILTIN, OUTPUT);
  sm.next(ledHigh);
}

void ledHigh()
{
  if (sm.previousStateIs(ledInit))
  {
    Serial.print("(from init) ");
  }
  Serial.println("high");
  digitalWrite(LED_BUILTIN, HIGH);
  sm.next(ledLow, 1000); //sm will freeze for 1000ms then chage to ledLow
}

void ledLow()
{
  if (sm.first())
  {
    Serial.println("low");
    digitalWrite(LED_BUILTIN, LOW);
  }
  if (sm.timeIsOver(1000))
  {
    sm.next(ledHigh);
  }
}

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}

