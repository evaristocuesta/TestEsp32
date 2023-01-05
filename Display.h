#ifndef DISPLAY_H
#define DISPLAY_H

#include "HT_SSD1306Wire.h"

class Display {
    private:
        SSD1306Wire  _display = SSD1306Wire(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); // addr , freq , i2c group , resolution , rst;
        int _interval;
        unsigned long _previousMillis;

        void show(float temperature) {
            _display.clear();
            _display.drawString(64, 4, "Temperature");
            String tempString = String(temperature);
            _display.drawString(64, 32, tempString + " ºC");
            _display.display();
        }       

    public:
        Display(int interval) {
            _interval = interval;
        }

        void setup() {
            pinMode(Vext,OUTPUT);
            digitalWrite(Vext, LOW);
            _display.init();
            _display.setTextAlignment(TEXT_ALIGN_CENTER);
            _display.screenRotate(ANGLE_0_DEGREE);
            _display.setFont(ArialMT_Plain_16);
            _previousMillis = millis() + _interval;
        }
    
        void update(float temperature) {
            unsigned long currentMillis = millis();
      
            if ((unsigned long)(currentMillis - _previousMillis) >= _interval) {
                show(temperature);
                _previousMillis = currentMillis;
            }
        }
};

#endif