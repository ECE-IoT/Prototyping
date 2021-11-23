#ifndef VERT_PROT_KEYS
#define VERT_PROT_KEYS

#include <Arduino.h>

class Keys
{
private:
  char* getKey(String path);
  char private_key_[];
  char device_key_[];
  char root_ca_[];

public:
  Keys();
  char getPrivateKey();
  char getDeviceKey();
  char getRootCA();
}

#endif
