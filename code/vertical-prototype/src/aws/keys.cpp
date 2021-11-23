#include "keys.h"
#include <Arduino.h>

Keys::Keys()
{
  this->private_key_ = getKey("PrivatePath");
  this->device_key_  = getKey("DevicePath");
  this->root_ca_     = getKey("RootCAPath");
}

Keys::getPrivateKey()
{
  return private_key_;
}

Keys::getDeviceKey()
{
  return device_key_;
}

Keys::getPrivateKey()
{
  return root_ca_;
}

Keys::getKey(String path)
{
  // read SPIFFS
}
