#ifndef VERT_PROT_KEYS
#define VERT_PROT_KEYS

#include <Arduino.h>
class Keys
{
  public:
    Keys();
    char* getPrivateKey();
    char* getDeviceCert();
    char* getRootCA();

  private:
    char* getKey(String path);
    char* private_key_;
    char* device_cert_;
    char* root_ca_;
};

#endif
