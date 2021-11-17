#ifndef VERT_PROT_AWS
#define VERT_PROT_AWS

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
  void readFromSPIFF(void);       // just examples
  void configureTLSClient(void);  // just examples
  void configureMQTTClient(void); // just examples

public:
  AWS()
  {
    this->init();
  }
  void publish(String topic, int payload);
  void subscribe(String topic, function<> callbackHandler);
}

#endif