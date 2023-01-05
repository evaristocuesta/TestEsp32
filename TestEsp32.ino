#include <string>
#include "BlinkLed.h"
#include "FadeLed.h"
#include "Temperature.h"
#include "Display.h"

static const uint8_t EXTERNAL_LED = 26;
static const int oneWireBus = 33;

BlinkLed blinkLed(EXTERNAL_LED, 2000);
FadeLed fadeLed(LED, 1000);
Temperature temperature(5000, oneWireBus);
Display display(5000);

void setup() {
  Serial.begin(115200);
  Serial.println("This is the setup");
  display.setup();
  temperature.setup();
}

void loop() {
  blinkLed.update();
  fadeLed.update();
  temperature.update();
  display.update(temperature.getTemperature());
}