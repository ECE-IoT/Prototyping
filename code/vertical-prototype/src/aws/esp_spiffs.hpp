#ifndef VERT_PROT_ESP_SPIFFS
#define VERT_PROT_ESP_SPIFFS

#include <Arduino.h>
#include <SPIFFS.h>

class ESP_SPIFFS
{
  public:
    ESP_SPIFFS();
    char* readSpiffs(String path);
    void appendLog(String message, String path);
    void createFile(String path);
};

#endif