#ifndef printer_h
#define printer_h

#include <Print.h>

class printer : public Print
{
  private :
    Print *out;

  public :
    printer() : out(NULL) {}
    printer(Print& output) : out(&output) {}

    inline void set(Print &output) {if (out != this) out = &output;} //let's try to avoid stack overflow
    inline void unset()            {out = NULL;}
    inline bool isSet() const      {return out != NULL;}
    inline void disable()          {unset();}     

    inline operator bool() {return isSet();}

    inline size_t write(uint8_t value) {return isSet() ? out->write(value) : 0;}
    inline size_t write(const uint8_t *buffer, size_t size) {return isSet() ? out->write(buffer, size) : 0;}
};

#endif