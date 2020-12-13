#include "easyRun.h"

/* Single task demo

A task is an object linked to a void function() as callback

1) define your callback function, for example loopCount() below
2) declare a task object linked to your function, for example loop1 below

each easyRun() will call your function

see task.h and callbacks.h for complete list of properties and methods 
*/

unsigned long count = 0;
unsigned long timeRef = 0;

void loopCount()
{
  count++;

  //Once per second
  if (millis() - timeRef >= 1000)
  {
    timeRef += 1000;
    Serial.println(count);
  }
}

task loop1(loopCount);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}
