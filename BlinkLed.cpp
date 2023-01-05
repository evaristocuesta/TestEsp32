#include "BlinkLed.h"

void BlinkLed::switchLed() 
{
    _state = _state ? LOW : HIGH;
    digitalWrite(_pin, _state);
}

BlinkLed::BlinkLed(uint8_t pin) 
{
    _state = 0;
    _pin = pin;
    _interval = 1000;
    pinMode(_pin, OUTPUT);
}

BlinkLed::BlinkLed(uint8_t pin, long interval) 
{
    _state = 0;
    _pin = pin;
    _interval = interval;
    pinMode(_pin, OUTPUT);
}

void BlinkLed::update() 
{
    unsigned long currentMillis = millis();
    
    if ((unsigned long)(currentMillis - _previousMillis) >= _interval) {
    switchLed();
    _previousMillis = currentMillis;
    }
}