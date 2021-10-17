<!--CATEGORIE / NAME OF THE SENSOR -->

# Wind velocity Sensor with the Anemometer

## Anemometer


- Supply voltage 7-24VDC
- Output range from 0.4V(0 m/s) to 2V(32.4m/s)
- Height: 105mm
- Center out to Cup: 102mm
- Arm length: 70mm
- Weight: 111.8g
- 3 pins: brown(power), black(GND), blue(signal)
- Working ambient temperature: -20°C - +50°C
- Working ambeint humidity: 35% - 85%
> More information can be found [here](https://how2electronics.com/measure-wind-speed-using-anemometer-arduino/)

> Can be ordered direct on the Adafruit homepage [here](https://www.adafruit.com/product/1733)

## Libraries

- [Adafruit_GFX.h](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit_SSD1306.h](https://github.com/adafruit/Adafruit-GFX-Library)


## Implementation

### Example Code

```
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    4  // Reset pin # (or -1 if sharing reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
 
 
void setup()
{
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.display();
  delay(100);
  display.clearDisplay();
 
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("Anemometer");
  display.display();
  delay(3000);
}
 
void loop()
{
  float sensorValue = analogRead(A0);
  Serial.print("Analog Value =");
  Serial.println(sensorValue);
 
  float voltage = (sensorValue / 1023) * 5;
  Serial.print("Voltage =");
  Serial.print(voltage);
  Serial.println(" V");
 
  float wind_speed = mapfloat(voltage, 0.4, 2, 0, 32.4);
  float speed_mph = ((wind_speed *3600)/1609.344);
  Serial.print("Wind Speed =");
  Serial.print(wind_speed);
  Serial.println("m/s");
  Serial.print(speed_mph);
  Serial.println("mph");
 
  display.clearDisplay();
 
  display.setTextSize(1);
  display.setCursor(30, 0);
  display.println("Wind Speed");
  
  display.setTextSize(2);
  display.setCursor(25, 30);
  display.print(speed_mph, 1);
  display.setTextSize(1);
  display.print(" mph");
 
  display.display();
 
  Serial.println(" ");
  delay(300);
}
 
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
```

## Picture of the sensor

![Anemometer](Anemometer.jpg)