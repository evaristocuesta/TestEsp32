class FadeLed : public BaseLed {
  private:
    bool _fadeIn;
    float _step;
    unsigned long _timeFadedLed;
    unsigned long _littleTimeFadedLed;

    void switchLed(unsigned long delta) {

      if (_timeFadedLed >= _interval) {
        _timeFadedLed = 0;
        _fadeIn = !_fadeIn;
      }

      _littleTimeFadedLed += delta;

      if (_littleTimeFadedLed > 40) {
        _state = _fadeIn ? _step * _timeFadedLed : 255 - _step * _timeFadedLed;
        analogWrite(_pin, _state);

        // Serial.print("Fade Led State: ");
        // Serial.print(_state);
        // Serial.print(" - Step: ");
        // Serial.print(_step);
        // Serial.print(" - littleTimeFadedLed: ");
        // Serial.println(_littleTimeFadedLed);
        
        _littleTimeFadedLed = 0;
      }
    }
  
  public:
    FadeLed(uint8_t pin) {
      _fadeIn = true;
      _state = 0;
      _pin = pin;
      _interval = 1000;
      _step = (float)255 / _interval;
      _timeFadedLed = 0;
      _littleTimeFadedLed = 0;
      pinMode(_pin, OUTPUT);
    }

    FadeLed(uint8_t pin, int interval) {
      _fadeIn = true;
      _state = 0;
      _pin = pin;
      _interval = interval;
      _step = (float)255 / _interval;
      _timeFadedLed = 0;
      _littleTimeFadedLed = 0;
      pinMode(_pin, OUTPUT);
    }

    void update() {
      unsigned long currentMillis = millis();
      unsigned long delta = currentMillis - _previousMillis;
      _timeFadedLed += delta;
      switchLed(delta);
      _previousMillis = currentMillis;
    }
};