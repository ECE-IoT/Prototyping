#include "connection-handler.hpp"
#include "secrets-esp32-d1mini-01.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <MQTTClient.h>
#include <WiFiClientSecure.h>
#include <pgmspace.h>

void callback(String& topic, String& payload);

WiFiClientSecure net_client = WiFiClientSecure();
MQTTClient mqtt_client      = MQTTClient(256);

void initWIFI(char ssid[], char pw[])
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pw);

  Serial.println("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println(".");
  }
}

void initAWS(char endpoint[], char sup_topic[])
{
  net_client.setCACert(AWS_CERT_CA);
  net_client.setCertificate(AWS_CERT_CRT);
  net_client.setPrivateKey(AWS_CERT_PRIVATE);

  mqtt_client.begin(endpoint, 8883, net_client);
  mqtt_client.onMessage(callback);

  Serial.println("Connecting to AWS IoT");

  while (!mqtt_client.connect(THINGNAME))
  {
    Serial.println(".");
    delay(100);
  }

  if (!mqtt_client.connected())
  {
    Serial.println("AWS IoT Timeout");
    return;
  }

  mqtt_client.subscribe(sup_topic);
  Serial.println("AWS IoT Connected");
}

void pubToAWS(char message[], char topic[])
{
  StaticJsonDocument<200> doc;
  char json_buffer[512];

  doc["time"]    = millis();
  doc["message"] = message;

  serializeJson(doc, json_buffer);
  mqtt_client.publish(topic, json_buffer);
  mqtt_client.loop();
}

void callback(String& topic, String& payload)
{
  Serial.println("Incoming: " + topic + " with " + payload);
}