#include "easyRun.h"

/*
runMeter provides statistics about run() duration of any monitored esayRun object
*/

void simulate_200ms_task()
{
  delay(200);
}
task t1(simulate_200ms_task);

void simulate_300ms_task()
{
  delay(300);
}
task t2(simulate_300ms_task);

runMeter trace1(t1,"T1");
runMeter trace2(t2,"T2");

loopMeter lm; //optional

void setup()
{
  Serial.begin(115200);
  delay(500);
  Serial.println("\nrunMeter demo");
}

void loop()
{
  easyRun();
}
