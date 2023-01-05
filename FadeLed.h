#ifndef FADED_LED_H
#define FADED_LED_H

#include "Arduino.h"
#include "BaseLed.h"

class FadeLed : public BaseLed {
  private:
    bool _fadeIn;
    float _step;
    unsigned long _timeFadedLed;
    unsigned long _littleTimeFadedLed;

    void switchLed(unsigned long delta);
  
  public:
    FadeLed(uint8_t pin);
    FadeLed(uint8_t pin, int interval);
    void update();
};

#endif