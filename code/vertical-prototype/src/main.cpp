#include "../secrets/wifi-secrets.h"
#include "aws/aws.h"
#include "sensor/sensor.h"
#include "sensor/iot-json-parser.h"
#include <Arduino.h>

#define MEAS_DELAY 60000
#define DHTTYPE 22
#define DHTPIN 2

AWS aws;
Parser parser;
VEML7700 sensor_1;
SoilMoisture sensor_2;
DHT_Sensor sensor_3 = DHT_Sensor(DHTTYPE, DHTPIN);

char *payload;
float value;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start");

  //----------- init wifi -----------
  WiFi.mode(WIFI_STA);
  WiFi.begin(FH_SSID, FH_PW);
  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
  //---------------------------------
  sensor_1.beginVEML7700();
  sensor_2.beginSoilMoisture();
  sensor_3.beginDHT22();
  aws.begin("aq60dkt3q20bd-ats.iot.eu-central-1.amazonaws.com", 8883, "esp32-d1mini-01");
  aws.subscribe("esp32/sub");
  delay(500);
}

void loop()
{
  static unsigned long last_meas = millis();
  if ((millis() - last_meas) >= MEAS_DELAY)
    {
    //----------- veml7700 ----------- 
    value = sensor_1.readBrightness();
    payload = parser.parseData("VEML7700", "lx", value);
    aws.publish("esp32/pub", payload);
    //--------------------------------

    //----------- SoilMoisture -------
    value = sensor_2.readTemp();
    payload = parser.parseData("SoilMoisture", "°C", value);
    aws.publish("esp32/pub", payload);
    //--------------------------------

    //----------- SoilMoisture -------
    value = sensor_2.readMoisture();
    payload = parser.parseData("SoilMoisture", "%", value);
    aws.publish("esp32/pub", payload);
    //--------------------------------

    //----------- DHT22 ----------- 
    value = sensor_3.readTempDHT22();
    payload = parser.parseData("DHT22", "°C", value);
    aws.publish("esp32/pub", payload);
    //--------------------------------

    //----------- DHT22 ------------- 
    value = sensor_3.readHumDHT22();
    payload = parser.parseData("DHT22", "%", value);
    aws.publish("esp32/pub", payload);
    //--------------------------------

    last_meas = millis();
  }
}