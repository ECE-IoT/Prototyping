# Arduino IoT Cloud example

## About the example.
The goal of this application is to measure temperature and humidity with an Arduino mkr 1010 board, periodically transfer the measured values to the cloud and display them on a dashboard. There is also an LED connected to the Arduino that can be turned on and off with a button on the dashboard.

## Implementation

###Config at AIC

I created an thing named **example_aplication** . The thing contains three variables. Two float read only variables (mkr1010_humid and mkr1010_temp) to get temperature and humidity values. These two variables are automatically updated to the cloud every second. The thrid variable is a bool read and write variable (mkr1010_led). It is used to control the connected LED and is updated when the variable is changed on the device or in the AIC.

Furthermore, the device (Arduino mkr 1010) had to be added and the network information had to be specified.

###Generated Sketch

All configuration was done on the AIC website and the sketch file was created automatically. I downloaded the sketch and edited it witch PlatformIO. Steps involved to do that are described [here](doc-aic-getting-started.md). Besides the main code wiht a setup() and void() the sketch also includes the files thingProperties.h and arduino_secrets.h.

**thingProperties.h**

In that generated file is the configuration for the created variables and the wifi connection. I removed the thing id, but you cant find it in the sharpoint fodler under ***"Dateien\Administration\Arduino IoT Cloud\Wifi and thing id.txt"***

```
#include "ArduinoIoTCloud.h"
#include "Arduino_ConnectionHandler.h"
#include "arduino_secrets.h"


const char THING_ID[] = "enter thing ID";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onMkr1010LedChange();

float mkr1010_humid;
bool mkr1010_led;
float mkr1010_temp;

void initProperties()
{
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(mkr1010_humid, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(mkr1010_led, READWRITE, ON_CHANGE, onMkr1010LedChange);
  ArduinoCloud.addProperty(mkr1010_temp, READ, 1 * SECONDS, NULL);
}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
```

**arduino_secrets.h**

This file cotains the network information. At the Fh we can use the ECEmbedded network. The related information can be found in the sharpoint fodler under ***"Dateien\Administration\Arduino IoT Cloud\Wifi and thing id.txt"***
```
#define SECRET_SSID "enter ssid"
#define SECRET_PASS "enter password"
```
**main**

Originally a main was created with the following structure.
```
#include <Arduino.h>
#include "arduino_secrets.h"
#include "thingProperties.h"

setup()
{
  // Initialize serial and wait for port to open:
  Serial.begin(9600);

  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

}

loop()
{
  ArduinoCloud.update();
}

void onMkr1010LedChange()  
{
  
}
```
Most of the code is self-explanatory.

The function **ArduinoCloud.update();** is used to reset the Watchdogtimer frequently.

> The purpose of the Watchdog is to restart the arduino when it does not work corectly. To detect this the watchdog counts down from a certain number and when zero is reached it detects an error and resets the arduino. Therefore the timer must be reset often.

The function onMkr1010LedChange() is called from the AIC when a value change of the mkr1010_led variable happend.

### Implementation of the measurement and the LED.

The code to measure temperature and humidity and the sensor is described [here](../arduino-hardware/doc-ahw-temp-humid.md). This code is used in the main.

An example how to controll an LED can be found [here](https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink). 

**More changes**
I have adapted the main of the example so that by inserting the functions **example_setup()** **example_loop()** the program is executed.

You can add the following code to your main.cpp in the src folder and it should work.

```
#include <arduino.h>
#include "aic_example/example_main.hpp"

void setup() 
{
  example_setup();
}

void loop() 
{
  example_loop();
}
```
**Necessary libraries**

- ArduinoIoTCloud.h
- Arduino_ConnectionHandler.h
- Adafruit_Sensor.h
- DHT.h

Add the following code to your libraries, if not already present.

```
lib_deps = 
	adafruit/DHT sensor library@^1.4.2
	adafruit/Adafruit Unified Sensor@^1.1.4
	arduino-libraries/ArduinoIoTCloud@^1.2.1
	arduino-libraries/Arduino_ConnectionHandler@^0.6.4
```
### How to connect the sensor and the LED
In the example the LED is vonnect at pin 1 and the data output of the DHT11 is connected to pin 0. I used a 220 Ohm resistor for the LED circuit.

### Dashboard
On the aic website, under dashboards, you will find a large number of widgets that you can simply click together and connect to the variables. I have clicked a few together. This dashboard can be viewed on the website or in the AIC app.

## More information
More information (e.g. login to AIC, getting started with AIC) can be found [here](doc-aic-getting-started.md).