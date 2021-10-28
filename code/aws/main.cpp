#include "../secrets/wifi-secrets.h"
#include "onboard-certificates/code/connection-handler.hpp"

#include <Arduino.h>

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

void setup()
{
  Serial.begin(9600);
  initWIFI(H_WIFI_SSID, H_WIFI_PASSWORD);
  initAWS(AWS_IOT_ENDPOINT, AWS_IOT_SUBSCRIBE_TOPIC);
}

void loop()
{
  pubToAWS("Hello World", AWS_IOT_PUBLISH_TOPIC);
  delay(1000);
}