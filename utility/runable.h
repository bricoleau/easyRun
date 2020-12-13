#ifndef runable_h
#define runable_h

#include <Arduino.h>

//Generic : any class with a "void run();" method
class runable
{
  protected :
    virtual void run() = 0; //must be defined in each derived class

  public :
    static void runAll(); //run all runable instances from all derived classes

    runable();
    ~runable();

    void setFirstRunable();
    void setLastRunable();
    void setBeforeRunable(runable &next);
    void setAfterRunable(runable &previous);
    static uint16_t nbRunable();

  private :
    //linked list of allocated items
    static runable* rootRunable;
    runable* nextRunable;
    void addFirstRunable();
    void addBeforeRunable(runable &next);
    void addAfterRunable(runable &previous);
    void addLastRunable();
    void removeRunable();

    //assignment and copy are not handled in linked list
    runable& operator=(const runable&); //Prevent assignment
    runable(const runable&);            //Prevent copy-construction
};

#endif