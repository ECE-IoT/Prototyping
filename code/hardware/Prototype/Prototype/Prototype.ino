// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include <Wire.h>
#include <Adafruit_LPS2X.h>
#include <Adafruit_Sensor.h>

Adafruit_LPS25 lps;

#define DHTPIN 33     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

#define DHTTYPE DHT22   

// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 
const int potPin = 34;

// variable for storing the potentiometer value
int potValue = 0;
//variable for storing the velocity in m/s
float velocity = 0;
//variable for storing the velocity in km/h
float velocity_kmh = 0;
//variable for storing the threshhold of the sensor
int threshhold = 346;
//variable for defining the maximum speed of the sensor in m/s 
float max_speed = 32.4;
//variable for storing the conversion factor from m/s to km/h
float convert_to_kmh = 3.6;
//variable for storing the resolution of the sensor
int resolution = 1300;

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens
  
  Serial.println(F("DHTxx test!"));
  Serial.println("Adafruit LPS25 test!");

  // Try to initialize!
  if (!lps.begin_I2C()) 
  {
  //if (!lps.begin_SPI(LPS_CS)) {
  //if (!lps.begin_SPI(LPS_CS, LPS_SCK, LPS_MISO, LPS_MOSI)) {
    Serial.println("Failed to find LPS25 chip");
    while (1) { delay(10); }
  }
  Serial.println("LPS25 Found!");

  //  lps.setDataRate(LPS25_RATE_12_5_HZ);
  Serial.print("Data rate set to: ");
  switch (lps.getDataRate()) 
  {
    case LPS25_RATE_ONE_SHOT: Serial.println("One Shot"); break;
    case LPS25_RATE_1_HZ: Serial.println("1 Hz"); break;
    case LPS25_RATE_7_HZ: Serial.println("7 Hz"); break;
    case LPS25_RATE_12_5_HZ: Serial.println("12.5 Hz"); break;
    case LPS25_RATE_25_HZ: Serial.println("25 Hz"); break;
  }
  dht.begin();
  //Wire.begin();                // join i2c bus (address optional for master)
}

void loop() 
{
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Reading potentiometer value
  potValue = analogRead(potPin);
  velocity =  (potValue - threshhold)*float(max_speed/resolution);
  velocity_kmh = velocity * convert_to_kmh;
  Serial.print("Windgeschwindigkeit:");
  Serial.print(velocity);
  Serial.print("m/s ");
  Serial.print(velocity_kmh);
  Serial.print("km/h ");

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  sensors_event_t temp;
  sensors_event_t pressure;
  lps.getEvent(&pressure, &temp);// get pressure
  Serial.print("Temperature: ");Serial.print(temp.temperature);Serial.println(" degrees C");
  Serial.print("Pressure: ");Serial.print(pressure.pressure);Serial.println(" hPa");
  Serial.println("");
  //delay(1000);
 
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
