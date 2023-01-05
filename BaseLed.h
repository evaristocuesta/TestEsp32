#ifndef BASE_LED_H
#define BASE_LED_H

#include "Arduino.h"

class BaseLed 
{
  
    protected:
        uint8_t _pin;
        long _interval;
        uint8_t _state;
        unsigned long _previousMillis;

    public:
      virtual void update();
      uint8_t getPin();
      unsigned long getInterval();
      void setInterval(unsigned long value);
      uint8_t getState();
      void setState(uint8_t value);
};

#endif