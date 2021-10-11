#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "DHT.h"

#define DHTPIN D7
#define DHTTYPE DHT11

#define MEAS_DELAY 1000 // delay in ms

DHT dht(DHTPIN, DHTTYPE);

float act_temp = 0; // last measured temperature
float act_humid = 0; // last measured humidity

void setup() 
{
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  static unsigned long last_meas = millis();
  
  if((millis() - last_meas) >= MEAS_DELAY)
  {
    act_temp = dht.readTemperature();
    act_humid = dht.readHumidity();

    Serial.print("Temperature: ");
    Serial.print(act_temp);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(act_humid);
    Serial.println(" %");

    last_meas = millis();
  }
}