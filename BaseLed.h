class BaseLed {
  protected:
    uint8_t _pin;
    long _interval;
    uint8_t _state;
    unsigned long _previousMillis;

  public:
    virtual void update();
    
    uint8_t getPin() {
      return _pin;
    }

    long getInterval() {
      return _interval;
    }

    void setInterval(long value) {
      _interval = value;
    }

    uint8_t getState() {
      return _state;
    }

    void setState(uint8_t value) {
      _state = value;
    }
};