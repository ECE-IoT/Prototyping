/*
Examples of typical brightness levels:

    at night: 0.5
    street lighting: 10
    living room: 50
    hall lighting: 100
    office room: 500
    overcast Himmel: 5000
    daylight: 10000
    bright sky: 20000
*/
#include "classes.h"

VEML7700 sensor_brightness;
SoilMoisture sensor_moisture;

void setup()
{
  Serial.begin(9600);

  if (!veml.begin())
  {
    Serial.println("Sensor not found");
    while(1);
  }
  
  veml.setGain(gain);
  veml.setIntegrationTime(integration_time);
  veml.interruptEnable(true);
 
  if (!ss.begin(0x36))
  {
    Serial.println("ERROR! seesaw not found");
    while(1);
  }
  else
  {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
}

void loop()
{
  float brightness_lux = sensor_brightness.readBrightness();
  float temperature_C = sensor_moisture.readTemp();
  int soil_moisture_percent = sensor_moisture.readMoisture();

  Serial.print("Brightness: ");
  Serial.print(brightness_lux, 1);
  Serial.println(" lx");

  Serial.print("Temperature: ");
  Serial.print(temperature_C, 1);
  Serial.println(" C°");
  
  Serial.print("Soil moisture: ");
  Serial.print(soil_moisture_percent);
  Serial.println(" %");
  Serial.println("");
  
  delay(2000);
}