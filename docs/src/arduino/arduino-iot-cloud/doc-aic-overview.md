# Arduino IoT Cloud overview
<!-- Macht die Strukturierung so Sinn? -->

## Concept
In the beginning a thing is created. A device is assigned to it. For a thing, several variables can be created, which can have different functionalities and are automatically synchronized with the device. Furthermore, network information must be specified. From this information, a code is automatically generated, which does all the work for the user. The user now only has to insert his own code (e.g. read temperature sensor) and all the work around has already been done automatically.

> The AIC and the whole process seems to me that it is actually what should come out of our project.
<!-- TODO -->

## Web editor
It is possible to edit, compile and load code on devices with this editor. 

Pros:
- Included libraries are automatically found during compiling.
- Code is automatically saved in the cloud.

Cons:
- The code is compiled on Arduino servers, which takes more time than compiling with PLatformIO on my PC.
- Git can not be used

> In my opinion not interesting for our applications.

## Dashboard
The AIC provides a set of widgets to display and control the variables of a thing. The dashboard can be accessed through the AIC website and the AIC App.

## Libraries

<!-- Mehr Beschreibung einfügen -->
The following two libraries are central to using a device with the AIC.

**[ArduinoIoTCloud](https://github.com/arduino-libraries/ArduinoIoTCloud)**

The ArduinoIoTCloud library is the central element of the firmware enabling certain Arduino boards to connect to the Arduino IoT Cloud.

**[Arduino_ConnectionHandler](https://github.com/arduino-libraries/Arduino_ConnectionHandler)**

Library for handling and managing network connections by providing keep-alive functionality and automatic reconnection in case of connection-loss.

## API
Provides a set of endpoints to manage Arduino IoT Cloud Devices, Things, Properties and Timeseries. This API can be called just with any HTTP Client, or using one of these clients:

- [Javascript NPM package](https://www.npmjs.com/package/@arduino/arduino-iot-client)
- [Python PYPI Package](https://pypi.org/project/arduino-iot-client/)
- [Golang Module](https://github.com/arduino/iot-client-go)

> Not tested anything yet.

## Security
All IoT device communications to the cloud use the industry standard SSL protocol for encryption. Arduino MKR and Arduino Portenta board families have on-board crypto-authentication chips and are further secured using X.509 certificate-based authentication.
> further research necessary. What exactly is the crypto authentication chip used for?

## Source of information
This description ist mainly based on the following sources:

<!-- Add recources -->
