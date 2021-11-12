# ESP32 connection to AWS IoT with MQTT

The following part gives a brief overview on how to connect an ESP32 microcontroller to AWS IoT Core over MQTT with TLS.

> A detailed description can be found [here](https://iot-esp32.workshop.aws/en/module1/getting_started.html)

## TLS a short description

TLS [Transport Layer Security] is a encryption protocol which is used to ensure secure data transmission on the Internet. Basically, TLS consists of the two components **TLS Handshake** and **TLS Record**. During the *TLS Handshake* a secure key exchange and authentication of both communication partners takes place. The symmetric key negotiated by the *TLS Handshake* is then used in the *TLS Record* for data transmission. 

!!! Links
  - [Data Protection for AWS](https://docs.aws.amazon.com/iot/latest/developerguide/transport-security.html)
  - [TLS Overview](https://de.wikipedia.org/wiki/Transport_Layer_Security)
  - [TLS Overview German Version](https://www.security-insider.de/was-ist-tls-transport-layer-security-a-673066/)

## Configuration of the ESP32 - The Code

In the `connection-handler.cpp` there are several helper methods which simplify the connection process to the WIFI and respectively to AWS IoT Core.

```cpp
void initWiFi(char ssid[], char pw[])
```

This method handles the connection to the local WIFI. It won't check the connection again if it's established once. This method is just used for setting everything up. 

```cpp
void initAWS(char endpoint[], char sup_topic[])
```

This method configures a globally generated instance of `WiFiClientSecure` with the required certificates for a TLS connection. Those are:

- Certificate for the CA (Certification Authority)
- Device Certificate 
- Private Device Key

In the next step the instance of `WiFiClientSecure` will be passed to the `.begin()` method of a `MQTTClient` instance. In order to be able to receive MQTT messages from the *AWS broker* the next step is to register a `callback` function for the MQTT client. Next the MQTT connection is going to be established. The last step is the subscription to the given topic. 

```cpp
void pubToAWS(char message[], char topic[])
```

This functions use is to simplify the task of publishing a new payload to a certain topic. For the example given the payload is just a `char` string. Later on there can be anything passed as the payload for this function. 

### References

!!! Links
  - [Example Code given by AWS](https://github.com/aws-samples/aws-iot-esp32-arduino-examples)


## Setting up AWS 

Every step of configuration is done in the *AWS IoT Core console*. The following list shows the necessary step which need to be done in order to connect the ESP

1. Create a policy with a name for the desired types of devices. Example Policy could look like this: 

```json
{
    "Version": "2012-10-17",
    "Statement": [{
            "Effect": "Allow",
            "Action": "iot:Connect",
            "Resource": "arn:aws:iot:REGION:ACCOUNT_ID:client/${iot:Connection.Thing.ThingName}"
        },
        {
            "Effect": "Allow",
            "Action": "iot:Subscribe",
            "Resource": "arn:aws:iot:REGION:ACCOUNT_ID:topicfilter/esp32/sub"
        },
        {
            "Effect": "Allow",
            "Action": "iot:Receive",
            "Resource": "arn:aws:iot:REGION:ACCOUNT_ID:topic/esp32/sub"
        },
        {
            "Effect": "Allow",
            "Action": "iot:Publish",
            "Resource": "arn:aws:iot:REGION:ACCOUNT_ID:topic/esp32/pub"
        }
    ]
}
```

2. On the IoT Core site download and test the connection kit
   1. Path: "Onboard/Onboard a Device/Get started"
   2. Choose suited environment (in the current case: Linux/OSX with `python`)
   3. Download and follow instructions 
3. Add a "thing" (Objekt) in the `tab`: *Manage/things/thing_name* with a chosen *thing_name*.
   1. Click onto the created thing -> actions/attach a policy -> select the policy name chosen above. 

### References

!!! Links
  - [AWS Policy and thing config](https://iot-esp32.workshop.aws/en/module1/getting_started.html#configure-aws-iot-librarys-sample-code-to-work-with-our-esp32)