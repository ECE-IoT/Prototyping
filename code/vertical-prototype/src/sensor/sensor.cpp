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

void DHT22::beginDHT22()
{
    dht.begin();
}

float DHT22::readTempDHT22()
{
    temp = dht.readTemperature();
    return temp;
}

float DHT22::readHumDHT22()
{
    hum = dht.readHumidity();
    return hum;
}
