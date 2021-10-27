#include "examples/onboard-certs/connection-handler.hpp"
#include "examples/onboard-certs/secrets-wifi-home.h"

#include <Arduino.h>

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

void setup()
{
  Serial.begin(115200);
  initWIFI(WIFI_SSID, WIFI_PASSWORD);
  initAWS(AWS_IOT_ENDPOINT, AWS_IOT_SUBSCRIBE_TOPIC);
}

void loop()
{
  pubToAWS("Hello World", AWS_IOT_PUBLISH_TOPIC);
  delay(1000);
}