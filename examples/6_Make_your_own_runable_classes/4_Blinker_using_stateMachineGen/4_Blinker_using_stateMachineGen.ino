#include "easyRun.h"

class blinker : public stateMachineGen
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
      println("HIGH");
      digitalWrite(_pin, HIGH);
      next(&blinker::high);
    }

    void high()
    {
      if (timeIsOver(_delay_ms))
      {
        println("LOW");
        digitalWrite(_pin, LOW);
        next(&blinker::low);
      }
    }

    void low()
    {
      if (time() >= _delay_ms) //another way to test time
      {
        println("HIGH");
        digitalWrite(_pin, HIGH);
        next(&blinker::high);
      }
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

