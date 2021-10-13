# Arduino IoT Cloud overview
<!-- Macht die Strukturierung so Sinn? -->

## Concept
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
