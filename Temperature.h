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

    float temperature() {
      _sensors.requestTemperaturesByIndex(0);
      float temperatureC = _sensors.getTempCByIndex(0);
      return temperatureC;
    }

  public: 
    Temperature(unsigned long interval, int oneWireBus) {
      _interval = interval;
      _oneWire = OneWire(oneWireBus);
      _sensors = DallasTemperature(&_oneWire);
    }

    void setup() {
      _sensors.begin();
      _temperature = temperature();
    }
    
    void update() {
      unsigned long currentMillis = millis();
      
      if ((unsigned long)(currentMillis - _previousMillis) >= _interval) {
        _temperature = temperature();
        _previousMillis = currentMillis;
      }
    }

    float getTemperature() {
      return _temperature;
    }
};

#endif