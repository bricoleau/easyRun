#include "easyRun.h"

/*
heartBeat also provides visual alerts using builtin led.
When your program encounter an abnormal case, you can be warned of this by flashes on the builtin led. 

see heartBeat.h for complete list of properties and methods
*/

heartBeat hb;

void setup()
{
  Serial.begin(115200);
  delay(500);

  //activate debug trace
  easyDebug.set(Serial);
}

void loop1()
{
  static bool ask = true;
  if (ask)
  {
    Serial.println("Enter error code (0=reset error)");
    ask = false;
  }
  if (Serial.available())
  {
    int i = Serial.parseInt();
    Serial.println(i);
    hb.raiseError(i);
    ask = true;
  }
}
task t1(loop1);

void loop()
{
  easyRun();
}