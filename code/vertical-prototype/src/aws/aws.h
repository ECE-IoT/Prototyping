#ifndef VERT_PROT_AWS
#define VERT_PROT_AWS

#include "keys.h"
#include <Arduino.h>
#include <ArduinoJson.hpp>
#include <MQTTClient.h>
#include <WiFiClientSecure.h>

using namespace std;

class AWS
{
private:
  MQTTClient mqtt_client;
  WiFiClientSecure tls_client;
  Keys key;

  void configureTLSClient(void);
  void configureMQTTClient(String endpoint[], uint16_t port, String device_name[]);

public:
  AWS(String endpoint[], uint16_t port, String device_name[]);
  void publish(String topic, int payload);
  void subscribe(String topic, function<> callbackHandler);
}

#endif