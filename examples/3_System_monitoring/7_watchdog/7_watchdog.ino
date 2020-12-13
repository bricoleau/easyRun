#include "easyRun.h"

//only for arduino AVR boards : uno, nano, mega, pro mini...

/*
watchdog allows to restart the system when stucked.
Restart occurs when the main loop lasts more than nnnn milliseconds.
Default nnnn is 4000

see watchdog.h for complete list of properties and methods
*/

watchdog dog; //That is the only thing you need to add watchdog security to your program

void restart()
{
  Serial.println("Entering restart section...");

  //This will take too long time : Restart should occurs before the end of the for loop.  
  for (uint8_t i=1; i<=10; i++)
  {
    delay(1000);
    Serial.println(i);
  }

  Serial.println("This shouldn't be printed");
  Serial.println("==> easyRun watchdog does not handle your board");
}

asyncTask t;

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.println("\nwatchdog demo");

  if (dog)
  {
    Serial.print("wathdog is activated, maximum loop() time is ");
    Serial.print(dog.cycle());
    Serial.println(" ms");
  }
  
  uint32_t time = 10000;
  Serial.print("Restart will be triggered in ");
  Serial.print(time);
  Serial.println(" milliseconds");
  t.set(restart, time);
}

void loop()
{
  easyRun();
}