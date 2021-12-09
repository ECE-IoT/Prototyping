#ifndef VERT_PROT_CONFIG
#define VERT_PROT_CONFIG
#include<Arduino.h>
#include <ArduinoJson.h>
#include "esp_spiffs.hpp"
#define CONFIG_FILE "/config_file.json"
/*------??
TODO Macht hier der zugriff über get Funktionen so Sinn, weil wir ja durch die Übergabe des Arrays ja erst wieder zugriff auf die privat Daten geben?
*/

class ESP_CONFIG
{
  private:
    char* aws_url;
    char* mqtt_topic;
    char* wifi_ssid;
    char* wifi_pswd;
    int aws_port;
    ESP_SPIFFS spiffs;

  public:
    ESP_CONFIG();
    char* getWifiSSID();
    char* getWifiPWSD();
    char* getMqttTopic();
    char* getAwsUrl();
    int getAwsPort();
};  

#endif