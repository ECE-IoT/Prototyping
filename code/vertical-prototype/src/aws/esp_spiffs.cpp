#include "esp_spiffs.hpp"

ESP_SPIFFS::ESP_SPIFFS()
{
  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS"); // Maybe implement a better error handling
    return;
  }
}

char* ESP_SPIFFS::readSpiffs(String path)
{
  File file = SPIFFS.open(path);

  if (!file)
  {
    return (char *)"\0"; // Error Handling überlegen
  }
  size_t size = file.size();
  char *file_content = (char *)malloc((size + 1) * sizeof(char));

  file.readBytes(file_content, size);
  file_content[size] = '\0';
  file.close();

  return file_content;
}

void ESP_SPIFFS::appendLog(String message, String path)
{
  File file = SPIFFS.open(path, "a");

  if (!file)
  {
   // Error Handling überlegen
  }

  file.println(message);
  file.close();
}

void ESP_SPIFFS::createFile(String path)
{
  File file = SPIFFS.open(path, "w+");

  if (!file)
  {
   // Error Handling überlegen
  }
  file.print("");
  file.close();

}
