#include "easyRun.h"

/*
A blinker is an object that makes a pin blinking.
Using a class allows to run several blinkers at the same time.

This example shows how to create a class derived from runable.
runable is the root class of any easyRun object
*/

class blinker : public runable
{
  // 1) define your private datas 
  private :
    int _pin, _state;
    unsigned long _delay_ms;
    unsigned long _millis_change;

  // 2) define constructor
  public :
    blinker(int pin, long delay_ms)
    {
      _pin = pin;
      _delay_ms = delay_ms;
      _millis_change = 0;
      pinMode(_pin, OUTPUT);
      low();
    }

  // 3) define methods
  protected :
    void println(const char *msg)
    {
      Serial.print(millis());
      Serial.print(", pin");
      Serial.print(_pin);
      Serial.print(' ');
      Serial.println(msg);
    }

    void high()
    {
      println("HIGH");
      _state = HIGH;
      digitalWrite(_pin, _state);
    }

    void low()
    {
      println("LOW");
      _state = LOW;
      digitalWrite(_pin, _state);
    }

    void run() // This will be called on each easyRun()
    {
      if (millis() - _millis_change >= _delay_ms)
      {
        if (_state == LOW)
        {
          high();
        }
        else
        {
          low();
        }
        _millis_change += _delay_ms;
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

