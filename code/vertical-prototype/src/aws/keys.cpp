#include "keys.h"
#include <Arduino.h>

Keys::Keys()
{
  this->private_key_ = getKey("PrivatePath");
  this->device_key_  = getKey("DevicePath");
  this->root_ca_     = getKey("RootCAPath");
}

const char* Keys::getPrivateKey()
{
  return private_key_;
}

const char* Keys::getDeviceKey()
{
  return device_key_;
}

const char* Keys::getRootCA()
{
  return root_ca_;
}

const char* Keys::getKey(String path)
{
  // read SPIFFS
}
