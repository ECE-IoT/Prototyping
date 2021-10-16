#include <Arduino.h>
<<<<<<< HEAD
#include <dht.h>
#include <Adafruit_Sensor.h>

#define MEAS_DELAY 1000
#define LED 6
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float act_temp = 0; // last measured temperature
float act_humid = 0; // last measured humidity

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    dht.begin();
=======
#include "arduino-hardware/temperatur/temp_meas.hpp"



void setup()
{
  tempSetup();
  // setup here
>>>>>>> b04181446c6de93884e06742ec1365b855f06313
}

void loop()
{
<<<<<<< HEAD
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
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
=======
  // loop function
>>>>>>> b04181446c6de93884e06742ec1365b855f06313
}
