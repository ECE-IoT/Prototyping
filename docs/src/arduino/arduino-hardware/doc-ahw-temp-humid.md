# Temperature and humidity Sensor DHT11

## DHT11

- Ultra low cost
- 3 to 5V power and I/O
- 2.5mA max current use during conversion (while requesting data)
- Good for 20-80% humidity readings with 5% accuracy
- Good for 0-50°C temperature readings ±2°C accuracy
- No more than 1 Hz sampling rate (once every second)
- Body size 15.5mm x 12mm x 5.5mm
- 4 pins with 0.1" spacing
> More information can be found [here](https://learn.adafruit.com/dht)


## Libraries

DHT.h and Adafruit_Sensor.h

## Implementation

To generate a DHT object it is necessary to specify the data Pin and wich sensor type is used.

```
#define DHTPIN 0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
```
In the setup() it is necessary to call.

```
dht.begin();
```
Now the temperature and humidity can be read by using:
```
float temp = dht.readTemperature();
float humid = dht.readHumidity();
```
<!-- Eventuell noch einen Schaltplan mit fritzing zeichnen und das sceduling beschreiben. -->