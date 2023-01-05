#ifndef BLINK_LED_H
#define BLINK_LED_H

#include "BaseLed.h"

class BlinkLed : public BaseLed {
  private:
    void switchLed() {
      _state = _state ? LOW : HIGH;
      digitalWrite(_pin, _state);
    }
  
  public:
    BlinkLed(uint8_t pin) {
      _state = 0;
      _pin = pin;
      _interval = 1000;
      pinMode(_pin, OUTPUT);
    }

    BlinkLed(uint8_t pin, long interval) {
      _state = 0;
      _pin = pin;
      _interval = interval;
      pinMode(_pin, OUTPUT);
    }

    void update() {
      unsigned long currentMillis = millis();
      
      if ((unsigned long)(currentMillis - _previousMillis) >= _interval) {
        switchLed();
        _previousMillis = currentMillis;
      }
    }
};

#endif