//#include "../secrets/wifi-secrets.h"
#include "aws/esp_config.hpp"
#include "aws/aws.h"
#include "aws/esp_wifi.hpp"
#include "aws/esp_logger.hpp"
#include "sensor/sensor.h"
#include "sensor/iot-json-parser.h"
#include <Arduino.h>
#include <WiFiClientSecure.h>

#define MEAS_DELAY 60000
#define DHTTYPE 22
#define DHTPIN 2

Parser parser;
VEML7700 sensor_1;
SoilMoisture sensor_2;
DHT_Sensor sensor_3 = DHT_Sensor(DHTTYPE, DHTPIN);

char *payload;
float value;
AWS aws;
  
void setup()
{
  Serial.begin(9600);
  Serial.println("Start");

  EspConfig conf;
  EspWifi wifi(conf.getWifiSSID(),conf.getWifiPWSD());
  EspLogger logger;

  logger.logBegin();
  wifi.beginWifi();
  
  logger.logInfo("wifi connected");
 
  //---------------------------------
  sensor_1.beginVEML7700();
  sensor_2.beginSoilMoisture();
  sensor_3.beginDHT22();

  aws.begin(conf.getAwsUrl(), conf.getAwsPort(), conf.getMqttTopic());
  logger.logInfo("aws connectedd");

  aws.subscribe("esp32/sub");
  logger.logInfo("aws subscribed");
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