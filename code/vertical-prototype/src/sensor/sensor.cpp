#include "sensor.h"

void VEML7700::beginVEML7700()
{
    if (!veml.begin())
    {
        Serial.println("Sensor not found");
        while (1)
            ;
    }
    veml.setGain(gain);
    veml.setIntegrationTime(integration_time);
    veml.interruptEnable(true);
}

float VEML7700::readBrightness()
{
    float brightness_value = veml.readLux();
    return brightness_value;
}

void SoilMoisture::beginSoilMoisture()
{
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

float SoilMoisture::readTemp()
{
    float temp_value = ss.getTemp();
    return temp_value;
}

int SoilMoisture::readMoisture()
{
    int capacity = ss.touchRead(0);
    int moisture_value = map(capacity, soil_moisture_level_low, soil_moisture_level_high, 100, 0);
    return moisture_value;
}

DHT_Sensor::DHT_Sensor(char type, char pin)
{
    dht_type_ = type;
    dht_pin_ = pin;
    dht = DHT(dht_pin_, dht_type_);
}

void DHT_Sensor::beginDHT22()
{
    dht.begin();
}

float DHT_Sensor::readTempDHT22()
{
   float temp = dht.readTemperature();
    return temp;
}

float DHT_Sensor::readHumDHT22()
{
    float hum = dht.readHumidity();
    return hum;
}
