//For checking compile with targeted board

#include "easyRun.h"

void doNothing()
{
}

unsigned long avoid_compiler_warning_on_unused_parameter;
void doNothingTime(uint32_t time)
{
  avoid_compiler_warning_on_unused_parameter = time;
}

task t1(doNothing);
asyncTask t2;
periodicTask t3(doNothing);

stateMachine sm1(doNothing);
fullMachine sm2(doNothing);

loopMeter lm;
heartBeat hb;
runMeter rm(hb, "heartBeat");
watchdog dog;

button  btn01(3);
mButton btn02(3);

clickButton  btn11(3, doNothing);
click2Button btn12(3, doNothing, doNothing);
click3Button btn13(3, doNothing, doNothing, doNothing);

actionButton  btn21(3, doNothing, doNothing);
action2Button btn22(3, doNothing, doNothing, doNothing, doNothing);
action3Button btn23(3, doNothing, doNothing, doNothing, doNothing, doNothing, doNothing);

toggleButton  btn31(3, doNothing, doNothing);
toggle2Button btn32(3, doNothing, doNothing, doNothing, doNothing);
toggle3Button btn33(3, doNothing, doNothing, doNothing, doNothing, doNothing, doNothing);

pressButton  btn41(3, doNothing, doNothing);
press2Button btn42(3, doNothing, doNothing, doNothing, doNothing);
press3Button btn43(3, doNothing, doNothing, doNothing, doNothing, doNothing, doNothing);

holdButton  btn51(3, doNothing, doNothingTime);
hold2Button btn52(3, doNothing, doNothingTime, doNothingTime);
hold2Button btn53(3, doNothing, doNothingTime, doNothing, doNothingTime);
hold3Button btn54(3, doNothing, doNothingTime, doNothingTime, doNothingTime);
hold3Button btn55(3, doNothing, doNothingTime, doNothing, doNothingTime, doNothing, doNothingTime);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}