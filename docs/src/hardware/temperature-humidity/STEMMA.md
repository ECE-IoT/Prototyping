# Adafruit STEMMA Soil/Moisture Sensor

## STEMMA

- Ultra small Design
- Can be used with 3.3V or 5V logic level
- Cas used also with an Raspberry PI with Python
- No more than 1 Hz sampling rate (once every second)
- Body size: 16.5mm x 16.5mm x 2.1mm
- Got two mounting holes with a diameter of 2.5mm for M2.5 screws
- Communication Interface: I2C
- Capacitive measurement
- provides a range from 200(very dry) to 2000(very wet)
- provides also the ambient temperature on the µC, but not with a high precision (+/-2°C)
- Includes an voltage regulator which provides 3.3V and 100mA
- 4 pins: Vin, GND, SCL, SDA
- Can be connected with a 4-pin JST-PH Connector
> More information can be found [here](https://learn.adafruit.com/adafruit-stemma-soil-sensor-i2c-capacitive-moisture-sensor)

## Picture of the sensor

![STEMMA circuit](STEMMA.png)

## Libraries

- ["Adafruit_seesaw.h"](https://github.com/adafruit/Adafruit_Seesaw)

## Implementation

### Example Code

```
#include "Adafruit_seesaw.h"

Adafruit_seesaw ss;

void setup() {
  Serial.begin(115200);

  Serial.println("seesaw Soil Sensor example!");
  
  if (!ss.begin(0x36)) {
    Serial.println("ERROR! seesaw not found");
    while(1);
  } else {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }
}

void loop() {
  float tempC = ss.getTemp();
  uint16_t capread = ss.touchRead(0);

  Serial.print("Temperature: "); Serial.print(tempC); Serial.println("*C");
  Serial.print("Capacitive: "); Serial.println(capread);
  delay(100);
}
```

## How to connect the sensor on the Arduino

![STEMMA circuit](STEMMA_circuit.png)

