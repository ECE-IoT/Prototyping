#ifndef VERT_PROT_SENSOR
#define VERT_PROT_SENSOR

#include "Arduino.h"
#include "Adafruit_VEML7700.h"
#include "Adafruit_seesaw.h"
#include <DHT.h>

#define gain 10
#define integration_time 400 // in ms
#define soil_moisture_level_low 1023
#define soil_moisture_level_high 314

class VEML7700
{
private:
    Adafruit_VEML7700 veml = Adafruit_VEML7700();

public:
    void beginVEML7700(void);
    float readBrightness(void);
};

class SoilMoisture
{
private:
    Adafruit_seesaw ss;

public:
    void beginSoilMoisture();
    float readTemp();
    int readMoisture();
};

class DHT22
{
private:
    char dht_type_;
    char dht_pin_;
    DHT dht;

public:
    DHT22(char type, char pin);
    void beginDHT22();
    float readTempDHT22();
    float readHumDHT22();
};

#endif