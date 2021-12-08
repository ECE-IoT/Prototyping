#include "esp_wifi.hpp"

ESP_WIFI::ESP_WIFI(char* wifi_ssid, char* wifi_pswd)
{
  ssid = wifi_ssid;
  pswd = wifi_pswd;
}

void ESP_WIFI::beginWifi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pswd);

  while (WiFi.status() != WL_CONNECTED)
  {
    //------!!!!!!!
    //TODO include writing to log file by timeout
  }
}

void ESP_WIFI::reconnectWifi()
{
  WiFi.reconnect();

  while (WiFi.status() != WL_CONNECTED)
  {
    //------!!!!!!!
    //TODO include writing to log file by timeout
  }
}

wl_status_t ESP_WIFI::statusWifi()
{
  return WiFi.status();
}