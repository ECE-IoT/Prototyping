#include "aws/aws.h"
#include <Arduino.h>

AWS aws;

void setup()
{
  aws.begin("aq60dkt3q20bd-ats.iot.eu-central-1.amazonaws.com", 8883, "esp32-d1mini-01");
}

void loop()
{
}