#include "easyRun.h"

/*
easyLog is a kind of manageable printer embedded in easyRun.h

Instead of using Serial.print() you may code :
- easyLog.print(...) for a few status messages
- esayDebug.print(...) for debugging purpose messages

each printer is linked to another printable object

easyLog : default set to Serial
easyDebug : default set to none

see printer.h for complete list of properties and methods 
*/

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.println("easyLog demo code");

  easyLog.println("This will be printed on Serial");
  easyDebug.println("This won't, because easyDebug is not set");

  easyDebug.set(Serial); //activating debug prints to Serial
  if (easyDebug.isSet())
  {
    easyLog.println("easyDebug is now activated");
  }
  easyDebug.println("debug info...");

  easyDebug.disable();
  if (easyDebug) //a printer can be tested as a boolean
  {
    easyLog.println("ugly... something went wrong : easyDebug is supposed to be unset");
  }
  else
  {
    easyLog.println("easyDebug is now deactivated");
  }
  easyDebug.println("This won't be printed");

  easyDebug.set(easyLog); //a better way to activate debug, linked to easyLog
  easyDebug.println("easyDebug is now re-activated, linked to easyLog");

  easyLog.disable(); //deactivate all

  easyLog.println("This won't be printed on Serial");
  easyDebug.println("Neither This");

  Serial.println("end of demo");
}

void loop()
{
}