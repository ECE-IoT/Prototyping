#include <Arduino.h>
#include <ArduinoMqttClient.h>
#include <WiFiNINA.h>

// ---------------- start definition of variables ----------------

WiFiSSLClient network = WiFiSSLClient();

// ----------------  end definition of variables  -----------------

void connectWifi(char ssid[], char pw[])
{
  WiFi.begin(ssid, pw);

  Serial.println("Connection to Wifi");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("-");
  }
}