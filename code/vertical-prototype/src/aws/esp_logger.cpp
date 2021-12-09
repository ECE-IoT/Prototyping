#include "esp_logger.hpp"

void ESP_LOGGER::logBegin()
{
  spiffs.spiffsBeginn();
  Serial.println("Last log file:");// TODO bessere Ausgabe für logging file finden (AWS, WebServer)
  Serial.println(spiffs.readSpiffs(LOG_FILE));

  spiffs.createFile(LOG_FILE); // create / erases the existing file
}

void ESP_LOGGER::logError(String message)
{
  String error_message = "ERROR "+ message + "  timestamp: "+ millis();
  spiffs.appendLog(error_message, LOG_FILE);

}

void ESP_LOGGER::logInfo(String message)
{
  String info_message = "INFO "+ message + "  timestamp: "+ millis();
  spiffs.appendLog(info_message, LOG_FILE);
}