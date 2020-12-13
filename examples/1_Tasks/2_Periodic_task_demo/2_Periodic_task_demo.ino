#include "easyRun.h"

/* Periodic task demo

A periodic task is an object linked to a void function(), with time condition

1) define your function, for example printOut() below
2) declare a periodicTask object linked to your function, for example t2 below

easyRun() will call your function each nnn milliseconds

see periodicTask.h and callbacks.h for complete list of properties and methods 
*/

unsigned long count = 0;

void counter()
{
  count++;
}
task t1(counter);

void printOut()
{
  Serial.print("millis()=");
  Serial.print(millis());
  Serial.print(", count=");
  Serial.println(count);
}
periodicTask t2(printOut, 1000); //To be executed each 1000 ms

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}
