# Arduino IoT Cloud procedure on device

## General procedure

### ThingProperties

In the file thingProperties.h the variables and callback functions are declared, a function initProperties() is defined and the WifiConnectionHandler is passed the SSID and the password of the Wifi. The function initProperties is used to create a property for each variable and to pass the ThingID to the ArduinoCloud obj.

- Properties

A porperty is created for each variable. This contains e.g. the current value, the value that the cloud has, assigned callback functions, read/write permissions, update policy (every x second, on change).

- ThingID

A unique ID for the thing created in the cloud. Used as a topic for MQTT.

### Main

- setup()

In the Main the function initProperties() is called. Then the function ArduinoCLoud.begin() is called. This function is basically used to pass the broker address, topics and a callback function to the MQTT client. The callback function is called when the MQTT client has received a message from the broker and processes it. Furthermore, the Crypto chip is woken up, the watchdog is started and it is checked if the firmware version of the wifi module is compatible.

- loop()

At each loop pass the update() is called. This function is the central part of the continuously running program. When called, first the watchdog is reset and then a state machine is processed. Both points are described in the following.

- watchdog

Used to reset the program if it got stuck somewhere.
Specifically, a timer counts down a count and when this reaches 0, the device is automatically restarted.
To ensure that the counter does not reach 0, it is reset each time update() is called.

- statemachine

The tasks: Establish network connection, establish broker connection, subscribe to the topics and publish to the topic are divided into states and are processed one after the other. It should be noted that if the network connection is lost, the process simply starts again from the beginning. Therefore, in each state is a check of the connection.

States:

* Establish a Wifi connection.
* Connect to the MQTT-Broker via TCP.
* Subscribe to the (shadow and data) MQTT-Topic which is related to the thing id.
* Get the values from the cloud via shadow topic.
* Last state, in the connected state it is checked with each call if the variables have to be sent to the cloud according to the update policy. If this is the case, an MQTT package is sent to the cloud.

## Connection from device to cloud and security

The device communicates with the cloud using MQTT messages, which are TCP encrypted. For the TCP encryption an implementation of BearSSL is used and specifically the versionTLS 1.2. For TLS a certificate is stored in the cryptochip. It was signed by Arduino and is used to authenticate the device. The encryption and decryption is completely outsourced to the cryptochip to save RAM.

More information to the [security](https://blog.arduino.cc/2020/07/02/arduino-security-primer/)
MOre information to [MQTT](https://de.wikipedia.org/wiki/MQTT)

## Encoding of the MQTT Data and Topic

Two topics exist for each device. A shadow topic and a data topic. The shadow topic is used to read the last variable values stored by the cloud at the beginning of the program and to store them in the properties. The data topic is used to send the data continuously to the cloud. All data to be sent is always encoded in a CBOR file and sent to the cloud together with a message. CBOR is similar to JSON, but more compact and a binary. It is specially designed to run on low power microcontrollers.

More information to [CBOR](https://de.wikipedia.org/wiki/Concise_Binary_Object_Representation)

 
