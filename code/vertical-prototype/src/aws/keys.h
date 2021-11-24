#ifndef VERT_PROT_KEYS
#define VERT_PROT_KEYS

#include <Arduino.h>
class Keys
{
private:
  const char* getKey(String path);
  const char* private_key_;
  const char* device_key_;
  const char* root_ca_;

public:
  Keys();
  const char* getPrivateKey();
  const char* getDeviceKey();
  const char* getRootCA();
};

#endif
