# Arduino IoT Cloud introduction
### TODO
- <span style="background-color: #F4A460; color: black">Drüber lesen und speziell die Rechtschreibung korrigieren&#128517. Für die Boards eventuell a eigene Seite erstellen 	.</span>

## What ist the Arduino IoT Cloud?
gute Frage

## Cloud compatible boards.
Currently (11/10/2021) the 9 official Arduino boards described below are compatible. Additionally many 3rd party boards based on the ESP32 / ESP8266 are also compatible.

#### [MKR Wifi 1010](https://store.arduino.cc/products/arduino-mkr1000-wifi?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: Wifi
- Special functions:  Li-Po charging circuit,  ECC508 crypto chip

#### [MKR Wifi 1000](https://store.arduino.cc/products/arduino-mkr-wifi-1010?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: Wifi, BLE
- Special functions:  Li-Po charging circuit,  ECC508 crypto chip

#### [Nano 33 IoT](https://store.arduino.cc/products/arduino-nano-rp2040-connect?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: Wifi, BLE
- Special functions: [IMU](https://en.wikipedia.org/wiki/Inertial_measurement_unit), ECC508 crypto chip, Cheapest Board!

#### [MKR WAN 1300](https://store.arduino.cc/products/arduino-mkr-wan-1300-lora-connectivity?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: LoRa
- Special functions:  low power consumption

#### [MKR WAN 1310](https://store.arduino.cc/products/arduino-mkr-wan-1310?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: LoRa
- Special functions:  low power consumption, ECC508 crypto chip

#### [MKR GSM 1400](https://store.arduino.cc/products/arduino-mkr-gsm-1400?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: GSM / 3G 
- Special functions: Li-Po charging circuit, ECC508 crypto chip

#### [MKR NB 1500](https://store.arduino.cc/products/arduino-mkr-nb-1500?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: NB LTE
- Special functions: low power consumption, Li-Po charging circuit, ECC508 crypto chip

#### [Nano RP2040 Connect](https://store.arduino.cc/products/arduino-nano-33-iot?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: Wifi, BLE
- Special functions: based on the Raspberry Pi RP2040, Microphone, [IMU](https://en.wikipedia.org/wiki/Inertial_measurement_unit), ECC608 crypto chip, Micropyhton support

#### [Portenta H7](https://store.arduino.cc/products/portenta-h7?_gl=1%2Aot1d9z%2A_ga%2AMTMxNDE3NTMxNi4xNjMyNzQzOTk1%2A_ga_NEXN8H46L5%2AMTYzMzk3MjMzNy4xNS4xLjE2MzM5NzQ2MjcuMA..)
- Connectivity: Wifi, BLE, Ethernet, Displayport output over USB-C
- Special functions: on board GPU, Li-Po charging circuit, generally for high level code with realtime taks, NXP SE050C2 crypto chip,  Micropyhton support

## Source of information
This introduction ist mainly based on the following sources:

- [An intro to the Arduino IoT Cloud](https://docs.arduino.cc/foundations/starting-guide/arduino-iot-cloud) from Arduino Docs.
- [Arduino IoT Cloud](https://github.com/arduino-libraries/ArduinoIoTCloud) library Github documentation.

