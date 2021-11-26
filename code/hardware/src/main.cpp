#include "classes.h"

VEML7700 sensor_brightness;
SoilMoisture sensor_moisture;

void setup()
{
  Serial.begin(9600);
  sensor_brightness.beginVEML7700();
  sensor_moisture.beginSoilMoisture();
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