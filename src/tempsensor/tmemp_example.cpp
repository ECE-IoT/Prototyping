/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/31791791-d3c0-4909-8987-20943af57de7 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float mkr1010_humid;
  bool mkr1010_led;
  float mkr1010_temp;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/
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