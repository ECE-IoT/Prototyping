#ifndef VERT_PROT_WIFI
#define VERT_PROT_WIFI

#include <Arduino.h>
#include <WiFiClientSecure.h>

class ESP_WIFI
{
  private:
  char* ssid;
  char* pswd;

  public:
  ESP_WIFI(char* wifi_ssid, char* wifi_pswd);
  void beginWifi();
  void reconnectWifi();
  wl_status_t statusWifi();
};

#endif