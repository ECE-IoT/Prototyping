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
  Keys keys;

  void configureTLSClient(void);
  void configureMQTTClient(char endpoint[], uint16_t port, char device_name[]);

public:
  AWS(char endpoint[], uint16_t port, char device_name[]);
  void publish(String topic, int payload);
  void subscribe(String topic);
};

#endif