#ifndef VERT_PROT_LOGGER
#define VERT_PROT_LOGGER
#include <Arduino.h>

class ESP_LOGGER
{
  public:
  void logError(String message);
  void logInfo(String message);
};
#endif