#include "../secrets/wifi-secrets.h"
#include "onboard-certificates/code/connection-handler.hpp"

#include <Arduino.h>

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC   "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

void setup()
{
  Serial.begin(9600);
  Serial.println(H_WIFI_PASSWORD H_WIFI_SSID);
  Serial.println(xPortGetCoreID());
  initWIFI(H_WIFI_SSID, H_WIFI_PASSWORD);
  initAWS(AWS_IOT_ENDPOINT, AWS_IOT_SUBSCRIBE_TOPIC);
}

void loop()
{
  pubToAWS("Hello World", AWS_IOT_PUBLISH_TOPIC);
  delay(1000);
}