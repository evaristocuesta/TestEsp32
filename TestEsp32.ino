#include "HT_SSD1306Wire.h"
#include <string>
#include "BlinkLed.h"
#include "FadeLed.h"
#include "Temperature.h"

static const uint8_t EXTERNAL_LED = 26;
static const int oneWireBus = 33;

SSD1306Wire  display(0x3c, 500000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED); // addr , freq , i2c group , resolution , rst

BlinkLed blinkLed(EXTERNAL_LED, 2000);
FadeLed fadeLed(LED, 2000);
Temperature temperature(5000, oneWireBus);

void setup() {
  Serial.begin(115200);
  Serial.println("This is the setup");
  setupText();
  temperature.setup();
}

void loop() {
  blinkLed.update();
  fadeLed.update();
  temperature.update();
  showDisplay(temperature.getTemperature());
}

void setupText() {
  pinMode(Vext,OUTPUT);
  digitalWrite(Vext, LOW);
  display.init();
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.screenRotate(ANGLE_0_DEGREE);
  display.setFont(ArialMT_Plain_16);
}

void showDisplay(float temperature) {
  display.clear();
  display.drawString(64, 4, "Temperature");
  String tempString = String(temperature);
  display.drawString(64, 32, tempString + " ºC");
  display.display();
}