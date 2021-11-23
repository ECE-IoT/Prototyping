#include "aws.h"
#include "keys.h"
#include <Arduino.h>
#include <ArduinoJson.hpp>
#include <MQTTClient.h>
#include <WiFiClientSecure.h>

AWS::AWS(String endpoint[], uint16_t port, String device_name[])
{
  configureTLSClient();
  configureMQTTClient();
}

AWS::configureTLSClient()
{
  tls_client = WiFiClientSecure();
  tls_client.setCACert(keys.getRootCA());
  tls_client.setPrivateKey(keys.getPrivateKey());
  tls_client.setCertificate(keys.getDeviceKey());
}

AWS::configureMQTTClient(String endpoint[], uint16_t port, String device_name[])
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