#include "../secrets/wifi-secrets.h"
#include "aws/aws.h"
#include <Arduino.h>

AWS aws;
const char* var = "25";

void setup()
{
  Serial.begin(9600);

  Serial.println("Start");

  /*init wifi*/
  WiFi.mode(WIFI_STA);
  WiFi.begin(J_SSID, J_PW);
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }

  aws.begin("aq60dkt3q20bd-ats.iot.eu-central-1.amazonaws.com", 8883, "esp32-d1mini-01");
  aws.subscribe("esp32/sub");
}

void loop()
{
  Serial.println("Publish");
  aws.publish("esp32/pub", var);
  delay(1000);
}