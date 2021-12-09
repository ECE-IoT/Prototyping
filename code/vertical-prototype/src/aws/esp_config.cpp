#include "esp_config.hpp"

ESP_CONFIG::ESP_CONFIG()
{
  spiffs.spiffsBeginn();
  char* json_file = spiffs.readSpiffs(CONFIG_FILE);
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, json_file);

  aws_url = strdup(doc["aws_url"]);
  mqtt_topic = strdup(doc["mqtt_topic"]);
  wifi_ssid = strdup(doc["ssid"]);
  wifi_pswd = strdup(doc["password"]);
  aws_port = doc["aws_port"];
}

char* ESP_CONFIG::getWifiSSID()
{
  return wifi_ssid;
}

char* ESP_CONFIG::getWifiPWSD()
{
  return wifi_pswd;
}

char* ESP_CONFIG::getMqttTopic()
{
  return mqtt_topic;
}

char* ESP_CONFIG::getAwsUrl()
{
  return aws_url;
}

int ESP_CONFIG::getAwsPort()
{
  return aws_port;
}