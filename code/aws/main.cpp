#include "examples/onboard-certs/connect-device.hpp"
#include "examples/onboard-certs/secrets.h"
#include <Arduino.h>

void setup()
{
  connectWifi(WIFI_SSID, WIFI_PASSWORD);
}

void loop()
{
  Serial.println("Wifi connected");
}