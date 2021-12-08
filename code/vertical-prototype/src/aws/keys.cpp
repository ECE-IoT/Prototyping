#include "keys.h"

void Keys::begin()
{
  // if (!SPIFFS.begin(true))
  // {
  //   Serial.println("An Error has occurred while mounting SPIFFS"); // Maybe implement a better error handling
  //   return;
  // }

  private_key_ = spiffs.readSpiffs("/esp32-d1mini-01.private.key"); // if we use a config file to configure the wifi we could
                                                         // also store these paths ther
  device_cert_ = spiffs.readSpiffs("/esp32-d1mini-01.cert.pem");
  root_ca_ = spiffs.readSpiffs("/root-CA.crt");
}

char *Keys::getPrivateKey()
{
  return private_key_;
}

char *Keys::getDeviceCert()
{
  return device_cert_;
}

char *Keys::getRootCA()
{
  return root_ca_;
}

// char *Keys::getKey(String path)
// {
//   File file = SPIFFS.open(path);

//   if (!file)
//   {
//     Serial.println("Failed to open file for reading. Fileame: ");
//     Serial.print(path);
//     return (char *)"\0";
//   }
//   size_t size = file.size();

//   char *file_content =
//       (char *)malloc((size + 1) * sizeof(char)); // Allocate storage from the Heap to prevent stackoverflow

//   file.readBytes(file_content, size);
//   file_content[size] = '\0'; /// this is neccassary because at the end of the readed file there is an @ and not \n
//   file.close();
//   return file_content;
// }
