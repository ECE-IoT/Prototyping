# Arduino IoT Cloud introduction
### TODO
- <span style="background-color: #F4A460; color: black">Drüber lesen und speziell die Rechtschreibung korrigieren&#128517. Für die Boards eventuell a eigene Seite erstellen 	.</span>

## What ist the Arduino IoT Cloud?
With the Arduino IoT Cloud desktop or mobile platform, you can quickly connect, manage and monitor your devices from anywhere in the world.

Arduino IoT Cloud allows you to automatically create any code to program your device with - just add a couple of lines to customize it how you want. If you’re new to Arduino don’t worry there’s example code for hundreds of sensors and actuators. 

The ArduinoIoTCloud library is the central element of the firmware enabling certain Arduino boards to connect to the Arduino IoT Cloud. The following boards are supported:

## Arduino IoT Cloud Components

### Devices
Physical objects built around a board (e.g. MKR WiFi 1010). This is the hardware which runs the sketch, reads sensors, controls actuators and communicates with the Arduino IoT Cloud.

### Things
Logical representation of a connected object. They embody inherent properties of the object, with as little reference to the actual hardware or code used to implement them. Each Thing is represented by a collection of Properties (e.g., temperature, light, pressure...).

### Properties
Qualities defining the characteristics of a system. A Property can be defined as read-only (READ) to indicate that Arduino IoT Cloud can read the data, but cannot change the value of such Property. On the other end, it may be designated to be read-and-write (READWRITE), allowing Arduino IoT Cloud to remotely change the property’s value and trigger an event notification on the device. It is also possible to mark properties as write-only (WRITE) which means the cloud can write to this property but not read its value (this limits data transmission for properties which are used to trigger events only).

1. Install the Arduino Create Agent plugin.
2. Check if you have a cloud compatible board. The picture below shows all official Arduino boards that are compatible.
3. Access the Arduino IoT Cloud from any page on arduino.cc by clicking on the bento menu (9-dots) on the top right corner, or you can go directly to the Arduino IoT Cloud.
4. Access the Arduino IoT Cloud from any page on arduino.cc by clicking on the bento menu (9-dots) on the top right corner, or you can go directly to the Arduino IoT Cloud.

## Creating a Thing
1. The user journey always begins by creating a new Thing. In the Thing overview, we can choose what device to use, what Wi-Fi network we want to connect to, and create variables that we can monitor and control.
2. Next we need to add a device by clicking on the "Select device" button on the Thing overview. Here, we choose from any board that we have already been configured, or select the Configure new device option.
3. Now we can add our first variable by clicking on the Add variable button. We can choose name, data type, update the setting and interaction mode for our variable. There are several data types we can choose from, such as int, float, boolean, long, char. There’s also special variables, such as Temperature, Velocity, and Luminance that can be used. The variables we create are automatically generated into a sketch file.
4. Finally, we need to connect to a Wi-Fi network by simply clicking the Configure button in the network section. Enter your network credentials and click Save. This information will also be generated into your sketch file!

## Building a Sketch
Now that you are all set up, let’s have a look at the interface!

A special sketch file can now be found in the Sketch tab, which includes all of the configurations that you have made. When the sketch has been uploaded, it will work as a regular sketch, but it will also update the Cloud variables that we use!

Additionally, each time we create a variable that has the Interaction Mode enabled, a function will also be generated. Every time this variable is triggered from the Cloud, it will execute the code within this function! This means that we can leave most of the code out of the loop() and only run code when needed.

When we are happy with our sketch, we can upload it to our board, by clicking the upload button.

After we have successfully uploaded the code, we can open the Serial Monitor tab to view information regarding our connection. If it is successful, it will print connected to network_name and connected to cloud.

If it fails to connect, it will print the errors here as well. Now that we have configured the device & network, created variables, completed the sketch and successfully uploaded the code, we can move on to the fun part, the dashboard!

## Creating the dashboard
Dashboards are visual user interfaces for interacting with your boards over the Cloud, and we can set up many different setups depending on what your IoT project needs.

We can access our dashboards by clicking on the Dashboards tab at the top of the Arduino IoT Cloud interface, where we can create new dashboards, and see a list of dashboards created for other Things.

If we click on Create new dashboard, we enter a dashboard editor. Here, we can create something called widgets. Widgets are the visual representation of our variables we create, and there are many different ones to choose from. Below is an example using several types of widgets.

The different widgets available.
The different widgets available.

When we create widgets, we also need to link them to our variables. This is done by clicking on a widget we create, selecting a Thing, and selecting a variable that we want to link.

Once it is linked, we can either interact with it, for example a button, or we can monitor a value from a sensor. As long as our board is connected to the cloud, the values will update automatically!
## Source of information
This introduction ist mainly based on the following sources:

- [An intro to the Arduino IoT Cloud](https://docs.arduino.cc/foundations/starting-guide/arduino-iot-cloud) from Arduino Docs.
- [Arduino IoT Cloud](https://github.com/arduino-libraries/ArduinoIoTCloud) library Github documentation.
