#include "easyRun.h"

//Mastering tasks order might be mandatory for some specific needs
//This example shows how to achieve it

void ffirst() {Serial.println("first task");}
void flast()  {Serial.println("last task");}
void fb()     {Serial.println("task b");}
void fa()     {Serial.println("task a");}
void fc()     {Serial.println("task c");}

task tfirst(ffirst);
task tlast(flast);
task tb(fb);
task ta(fa);
task tc(fc);

void setup()
{
  Serial.begin(115200);
  delay(500);

  Serial.println("\nDemo for mastering tasks order with easyRun");
  Serial.print(runable::nbRunable());
  Serial.println(" runable items activated");

  Serial.println("\nFirst run");
  easyRun();

  tfirst.setFirstRunable();
  tlast.setLastRunable();
  tb.setAfterRunable(ta);
  tc.setBeforeRunable(tlast);  
}

void loop()
{
  Serial.println("\nloop");
  easyRun();
  delay(5000);
}
