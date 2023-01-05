#include "BaseLed.h"

uint8_t BaseLed::getPin() 
{
    return _pin;
}

unsigned long BaseLed::getInterval() 
{
    return _interval;
}

void BaseLed::setInterval(unsigned long value) 
{
    _interval = value;
}

uint8_t BaseLed::getState() 
{
    return _state;
}

void BaseLed::setState(uint8_t value) 
{
    _state = value;
}