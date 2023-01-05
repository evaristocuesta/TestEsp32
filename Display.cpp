#include "Display.h"

void Display::show(float temperature) {
    _display.clear();
    _display.drawString(64, 4, "Temperature");
    String tempString = String(temperature);
    _display.drawString(64, 32, tempString + " ºC");
    _display.display();
}       

Display::Display(int interval) {
    _interval = interval;
}

void Display::setup() {
    pinMode(Vext,OUTPUT);
    digitalWrite(Vext, LOW);
    _display.init();
    _display.setTextAlignment(TEXT_ALIGN_CENTER);
    _display.screenRotate(ANGLE_0_DEGREE);
    _display.setFont(ArialMT_Plain_16);
    _previousMillis = millis() + _interval;
}

void Display::update(float temperature) {
    unsigned long currentMillis = millis();

    if ((unsigned long)(currentMillis - _previousMillis) >= _interval) {
        show(temperature);
        _previousMillis = currentMillis;
    }
}