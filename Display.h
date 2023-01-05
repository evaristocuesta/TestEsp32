#ifndef DISPLAY_H
#define DISPLAY_H

#include "HT_SSD1306Wire.h"

class Display 
{
    private:
        SSD1306Wire  _display = SSD1306Wire(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); // addr , freq , i2c group , resolution , rst;
        int _interval;
        unsigned long _previousMillis;

        void show(float temperature);

    public:
        Display(int interval); 
        void setup();
        void update(float temperature);
};

#endif