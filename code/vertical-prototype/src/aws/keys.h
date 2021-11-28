#ifndef VERT_PROT_KEYS
#define VERT_PROT_KEYS

#include <Arduino.h>
#include <SPIFFS.h>
class Keys
{
private:
  char *getKey(String path);
  char *private_key_;
  char *device_cert_;
  char *root_ca_;

public:
  void begin(void);
  char *getPrivateKey();
  char *getDeviceCert();
  char *getRootCA();
};

#endif
