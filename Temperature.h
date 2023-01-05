#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <DallasTemperature.h>

class Temperature {
  private:
    OneWire _oneWire;
    DallasTemperature _sensors;
    unsigned long _previousMillis;
    float _temperature;
    unsigned long _interval;

    float temperature();

  public: 
    Temperature(unsigned long interval, int oneWireBus);
    void setup();
    void update();
    float getTemperature();
};

#endif