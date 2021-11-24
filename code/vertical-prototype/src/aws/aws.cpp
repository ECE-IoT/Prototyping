#include "aws.h"
#include "keys.h"
#include <Arduino.h>
#include <ArduinoJson.hpp>
#include <MQTTClient.h>
#include <WiFiClientSecure.h>

void AWS::begin(char endpoint[], uint16_t port, char device_name[])
{
  keys.begin();
  configureTLSClient();
  configureMQTTClient(endpoint, port, device_name);
}

void AWS::configureTLSClient()
{
  tls_client = WiFiClientSecure();
  tls_client.setCACert(keys.getRootCA());
  tls_client.setPrivateKey(keys.getPrivateKey());
  tls_client.setCertificate(keys.getDeviceCert());
}

void AWS::configureMQTTClient(char endpoint[], uint16_t port, char device_name[])
{
  mqtt_client = MQTTClient(265); // 265 = buffer size
  mqtt_client.begin(endpoint, port, tls_client);

  while (!mqtt_client.connect(device_name))
  {
    delay(100);
  }

  if (!mqtt_client.connected())
  {
    return;
  }
}

void AWS::publish(char topic[], const char* payload)
{
  mqtt_client.publish(topic, payload);
  mqtt_client.loop();
}

void AWS::subscribe(char topic[])
{
  mqtt_client.subscribe(topic);
}