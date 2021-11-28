#include "../secrets/wifi-secrets.h"
#include "aws/aws.h"
#include "sensor/iot-json-parser.h"
#include <Arduino.h>

AWS aws;
Parser parser;
const char *var = "234";
char *payload;

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
  delay(500);
}

void loop()
{
  Serial.println("Publish");
  payload = parser.parseData("VEML", "LUX", 123.4);
  Serial.println(payload);
  aws.publish("esp32/pub", payload);
  delay(2000);
}