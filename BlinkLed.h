#ifndef BLINK_LED_H
#define BLINK_LED_H

#include "BaseLed.h"

class BlinkLed : public BaseLed 
{
    private:
      void switchLed();

    public:
      BlinkLed(uint8_t pin);
      BlinkLed(uint8_t pin, long interval);
      void update();
};

#endif