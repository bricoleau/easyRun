#include "easyRun.h"

/* Asynchonous task demo

An asynchronous task is an object linked to a void function(), executed once, with time condition

1) define your function, for example explode() below
2) declare a periodicTask object linked to your function, for example bomb below

easyRun() will call your function once, after nnn milliseconds

see asyncTask.h and callbacks.h for complete list of properties and methods 
*/

asyncTask bomb;

void explode()
{
  Serial.println("boom !");
}

void autoActivate()
{
  if (!bomb.isSet())
  {
    Serial.println("activating bomb");
    bomb.set(explode, 10000);
  }
}
task t1(autoActivate);

void countDown()
{
  int seconds = bomb.timeLeft() / 1000;
  if (seconds > 0)
  {
    Serial.println(seconds);
  } 
}
periodicTask t2(countDown, 1000);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}
