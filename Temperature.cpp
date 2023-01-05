#include "Temperature.h"

float Temperature::temperature() 
{
    _sensors.requestTemperaturesByIndex(0);
    float temperatureC = _sensors.getTempCByIndex(0);
    return temperatureC;
}

Temperature::Temperature(unsigned long interval, int pin) 
{
    _interval = interval;
    _oneWire = OneWire(pin);
    _sensors = DallasTemperature(&_oneWire);
}

void Temperature::setup() 
{
    _sensors.begin();
    _temperature = temperature();
}

void Temperature::update() 
{
    unsigned long currentMillis = millis();

    if ((unsigned long)(currentMillis - _previousMillis) >= _interval) 
    {
        _temperature = temperature();
        _previousMillis = currentMillis;
    }
}

float Temperature::getTemperature() 
{
    return _temperature;
}