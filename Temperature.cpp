#include "Temperature.h"

void Temperature::temperature() 
{
    _sensors.requestTemperaturesByIndex(0);
    _temperature = _sensors.getTempCByIndex(0);
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
    temperature();
    _asyncTask = AsyncTask(_interval, true, [&]() { this->temperature(); });    
    _asyncTask.Start();
}

void Temperature::update() 
{
    _asyncTask.Update();
}

float Temperature::getTemperature() 
{
    return _temperature;
}