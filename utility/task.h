#ifndef task_h
#define task_h

#include "runable.h"
#include "callbacks.h"

class task : public runable
{
  public :
    callbackVoid callback;
    
    task(callbackVoid::callback_t custom_callback = NULL) : callback(custom_callback) {}
    //constructor
    //task t1;
    //task t2(my_callback); //with void my_callback() {...}

    inline operator bool() {return callback.isSet();}
    //if (t1) {...}  //to test if t1 is linked to a callback 

    task& operator =(callbackVoid::callback_t custom_callback) {callback.set(custom_callback); return *this;}
    //t1 = my_callback;  //same as t2.callback.set(my_callback);

  protected :
    void run() {callback.execute();}
};

#endif