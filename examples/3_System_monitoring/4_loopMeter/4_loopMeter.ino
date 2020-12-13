#include "easyRun.h"

/*
loopMeter provides statistics about loop() duration
each loop() should be as fast as possible, in order to keep a high fluidity af all easyRun objects.  

see loopMeter.h for complete list of properties and methods
*/
loopMeter lm(5000); //default value is 10000

void setup()
{
  Serial.begin(115200);
  Serial.println("\nloopMeter demo");
}

void loop()
{
  easyRun();

  //after a while, let's simulate some heavy part of code
  if (millis() > 10000) delay(200);
}