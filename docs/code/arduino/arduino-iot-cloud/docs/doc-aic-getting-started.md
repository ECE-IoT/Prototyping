# Getting started

## General preperations

**Create Agent**

If you plan to use the Arduino web editor you have to install the Arduino create agent. (Can be found [here](https://support.arduino.cc/hc/en-us/articles/360014869820-How-to-install-the-Arduino-Create-Agent)).
It provides the functionality for the web editor to detect Arduino boards and other supported devices connected to the computer via USB, upload sketches and use the serial monitor.
> Note: Alternatively, PlatformIO can be used for programming. No create agent is required for PlatformIO.

**Access the AIC**

Access AIC from any page on arduino.cc by clicking on the bento menu (9-dots) on the top right corner, or you can go directly to AIC.

**Login**

An AIC account has already been created for the project group. The login informations can be found under *Dateien\Administration\Arduino IoT Cloud\Zugang.docx* in the share point folder.

## Creating a Thing
A new project starts by creating a new Ting.

We need to add a device by clicking on the "Select device" button on the Thing overview. Here, we choose from any board that we have already been configured, or select the Configure new device option.
> You can find a list of compatible boards [here](doc-aic-boards.md).

Next we can add a variable by clicking on the Add variable button. We can choose name, data type, update the setting and interaction mode for our variable. There are several data types we can choose from, such as int, float, boolean, long, char. There’s also special variables, such as Temperature, Velocity, and Luminance that can be used.

Finally, we need to connect to a Wi-Fi network by simply clicking the Configure button in the network section. Enter your network credentials and click Save. This information will also be generated into your sketch file!
> At the FH we can use the ECEmbedded Wi-Fi network. The Login information can be found in the students room.

## Building a Sketch

A special sketch file can now be found in the Sketch tab, which includes all of the configurations that you have made. When the sketch has been uploaded, it will work as a regular sketch, but it will also update the Cloud variables that we use!

Additionally, each time we create a variable that has the Interaction Mode enabled, a function will also be generated. Every time this variable is triggered from the Cloud, it will execute the code within this function! This means that we can leave most of the code out of the loop() and only run code when needed.

## How to use PlatformIO for the project?

The sketch can be editet with the web editor or you can download the sketch and use PlatformIO. PlatformIO provides the function **Import Arduino Project** wich can be found at the main page of the PlatformIO Gui.

In the Web Editor, the included libraries are automatically added to the project during compilation. At PlatformIO we have to add libraries at the **.ini** file with **lib_deps**. The libraries specified with lib_deps are automatically downloaded when the code is compiled. The PlatformIO Gui provides under the tab **Libraries** a function to search and add libraries to a project.

*Example:*
```
lib_deps = 
	adafruit/DHT sensor library@^1.4.2
	adafruit/Adafruit Unified Sensor@^1.1.4
	arduino-libraries/ArduinoIoTCloud@^1.2.1
	arduino-libraries/Arduino_ConnectionHandler@^0.6.4
```
> The advanteg of these library management ist that we can decide wihch version is supposed to be used. This should prevent us from getting into trouble by using different library versions.

## Creating the dashboard
Dashboards are visual user interfaces for interacting with your boards over the Cloud, and we can set up many different setups depending on what your IoT project needs.

We can access our dashboards by clicking on the Dashboards tab at the top of the Arduino IoT Cloud interface, where we can create new dashboards, and see a list of dashboards created for other Things.

If we click on Create new dashboard, we enter a dashboard editor. Here, we can create something called widgets. Widgets are the visual representation of our variables we create.

When we create widgets, we also need to link them to our variables. This is done by clicking on a widget we create, selecting a Thing, and selecting a variable that we want to link.

Once it is linked, we can either interact with it, for example a button, or we can monitor a value from a sensor. As long as our board is connected to the cloud, the values will update automatically!
> The dashboards can be accessed at the AIC website ore with the AIC App.
---

## Detailed description of the therminology used

**Abbreviations**

Arduinot IoT Cloud = AIC

**Devices**

Physical objects built around a board (e.g. MKR WiFi 1010). This is the hardware which runs the sketch, reads sensors, controls actuators and communicates with the Arduino IoT Cloud.

**Things**

Logical representation of a connected object. They embody inherent properties of the object, with as little reference to the actual hardware or code used to implement them. Each Thing is represented by a collection of Properties (e.g., temperature, light, pressure...).

**Properties**

Qualities defining the characteristics of a system. A Property can be defined as read-only (READ) to indicate that Arduino IoT Cloud can read the data, but cannot change the value of such Property. On the other end, it may be designated to be read-and-write (READWRITE), allowing Arduino IoT Cloud to remotely change the property’s value and trigger an event notification on the device. It is also possible to mark properties as write-only (WRITE) which means the cloud can write to this property but not read its value (this limits data transmission for properties which are used to trigger events only).

## Source of information
This description ist mainly based on the following sources:

- [An intro to the Arduino IoT Cloud](https://docs.arduino.cc/foundations/starting-guide/arduino-iot-cloud) from Arduino Docs.
- [Arduino IoT Cloud](https://github.com/arduino-libraries/ArduinoIoTCloud) library Github documentation.
