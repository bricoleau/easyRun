#ifndef easyRun_h
#define easyRun_h

 //Root abstract class
#include "utility/runable.h"

inline void easyRun() {runable::runAll();} //must be called once per loop()

//Various tasks classes
#include "utility/task.h"          //for calling a function on each easyRun() 
#include "utility/periodicTask.h"  //for calling a function each nnn milliseconds
#include "utility/asyncTask.h"     //for calling a function once, delayed by nnn milliseconds

//State machine classes
#include "utility/stateMachine.h"  //basic state machine
#include "utility/fullMachine.h"   //extended state machine

//Handling standard and debug printouts
#include "utility/easyLog.h"

//Leds
#include "utility/easyLed.h"       //led driver including PWM

//Buttons
#include "utility/button.h"
#include "utility/clickButton.h"
#include "utility/actionButton.h"
#include "utility/toggleButton.h"
#include "utility/pressButton.h"
#include "utility/holdButton.h"

//Other Goodies
#include "utility/watchdog.h"      //restart the system when stucked
#include "utility/heartBeat.h"     //light pulse on builtin led
#include "utility/loopMeter.h"     //provides printouts stats on main loop duration
#include "utility/runMeter.h"      //provides printouts stats on run duration

#endif