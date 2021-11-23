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

#include "Adafruit_VEML7700.h"
#include "Adafruit_seesaw.h"

#define gain 10
#define integration_time 400 // in ms
#define soil_moisture_level_low 689
#define soil_moisture_level_high 314

Adafruit_seesaw ss;
Adafruit_VEML7700 veml = Adafruit_VEML7700();

void setup()
{
  Serial.begin(115200);

  if (!veml.begin())
  {
    Serial.println("Sensor not found");
    while (1)
      ;
  }
  Serial.println("Sensor found");

  veml.setGain(gain);
  veml.setIntegrationTime(integration_time);
  veml.interruptEnable(true);

  if (!ss.begin(0x36))
  {
    Serial.println("ERROR! seesaw not found");
    while (1)
      ;
  }
  else
  {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
}

void loop()
{
  float temperature = ss.getTemp();
  int capacity = ss.touchRead(0);
  int soil_moisture_percent = map(capacity, soil_moisture_level_low, soil_moisture_level_high, 100, 0);

  Serial.print("Temperature: ");
  Serial.print(temperature, 1);
  Serial.println(" C°");

  Serial.print("Brightness: ");
  Serial.print(veml.readLux(), 1);
  Serial.println(" lx");

  Serial.print("Soil moisture: ");
  Serial.print(soil_moisture_percent);
  Serial.println(" %");
  Serial.println("");

  delay(2000);
}