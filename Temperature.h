#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <DallasTemperature.h>
#include "AsyncTaskLib.h"

class Temperature 
{
    private:
        OneWire _oneWire;
        DallasTemperature _sensors;
        float _temperature;
        unsigned long _interval;
        AsyncTask _asyncTask = AsyncTask(0);
        void temperature();

    public: 
        Temperature(unsigned long interval, int pin);
        void setup();
        void update();
        float getTemperature();
};

#endif