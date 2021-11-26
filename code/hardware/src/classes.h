#include "Adafruit_VEML7700.h"
#include "Adafruit_seesaw.h"

#define gain 10
#define integration_time 400 //in ms
#define soil_moisture_level_low 1023
#define soil_moisture_level_high 314

Adafruit_seesaw ss;
Adafruit_VEML7700 veml = Adafruit_VEML7700();

class VEML7700
{
  public:
    float readBrightness()
    {
      int capacity = ss.touchRead(0);
      int moisture_value = map(capacity, soil_moisture_level_low, soil_moisture_level_high, 100, 0);
      return moisture_value;  
    }
};

class SoilMoisture
{
  public:
    float readTemp()
    {
      float temp_value = ss.getTemp();
      return temp_value;
    }
    
    int readMoisture()
    {
      int capacity = ss.touchRead(0);
      int moisture_value = map(capacity, soil_moisture_level_low, soil_moisture_level_high, 100, 0);
      return moisture_value;
    }
};