#ifndef VERT_PROT_LOGGER
#define VERT_PROT_LOGGER
#include <Arduino.h>
#include "esp_spiffs.hpp"

#define LOG_FILE "/log_file.txt"

class ESP_LOGGER
{
  public:
  ESP_SPIFFS spiffs;
  void logBegin();
  void logError(String message);
  void logInfo(String message);
};
#endif