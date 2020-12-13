#include "easyRun.h"

class blinker : public fullMachineGen
{
  private :
    int _pin;
    unsigned long _delay_ms;

  public :
    blinker(int pin, long delay_ms)
    {
      _pin = pin;
      _delay_ms = delay_ms;
    }

  protected :
    void println(const char *msg)
    {
      Serial.print(millis());
      Serial.print(", pin");
      Serial.print(_pin);
      Serial.print(' ');
      Serial.println(msg);
    }

    void init()
    {
      println("init");
      pinMode(_pin, OUTPUT);
      next(&blinker::high);
    }

    void high()
    {
      println("HIGH");
      digitalWrite(_pin, HIGH);
      next(&blinker::low, _delay_ms);
    }

    void low()
    {
      println("LOW");
      digitalWrite(_pin, LOW);
      next(&blinker::high, _delay_ms);
    }
};

//Using a class allows to handle several blinkers 
blinker a(3, 2000);
blinker b(LED_BUILTIN, 1000);

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  easyRun();
}

