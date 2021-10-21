#!/usr/bin/env python3

"""
Created: 10/19/21
by: Tim Schmid

automatically update the src_filter in platformio.ini
"""

import os
import argparse
import configparser

envs = ["aws", "arduino"]
env_config = configparser.ConfigParser()

CLOUD_FILTER = "+<arduino/>  -<arduino/arduino-hardware/"
HARDWARE_FILTER = "+<arduino/> -<arduino/arduino-iot-cloud/>"
AWS_FILTER = "+<aws/> -<.git/>"

BASE_PATH = os.path.join(os.path.dirname(
    os.path.abspath(__file__)), os.pardir)
CONFIG_PATH = os.path.join(BASE_PATH, 'config')
ENV_PATH = os.path.join(CONFIG_PATH, 'env')
ENV_INI_PATH = os.path.join(CONFIG_PATH, "env", "env.ini")

def createFile():
  with open(ENV_INI_PATH, 'w') as env:
    env_config.read(ENV_INI_PATH)
    env_config.add_section("common")

    with open(ENV_INI_PATH, 'w') as f:
      env_config.write(f)

    print("--> new file created \n")

def checkFile():
    if not os.path.exists(CONFIG_PATH) and not os.path.exists(ENV_PATH):
      print("--> no file and no directory detected. A new file within a new directory will be created \n")
      os.mkdir(CONFIG_PATH, 0o755)
      os.mkdir(os.path.join(CONFIG_PATH, "env"), 0o755)
      createFile()
    elif os.path.exists(CONFIG_PATH) and not os.path.exists(ENV_PATH):
      print("--> no file detected. A new file will be created \n")
      os.mkdir(os.path.join(CONFIG_PATH, "env"), 0o755)
      createFile()


def setEnvironment():
  parser = argparse.ArgumentParser()
  parser.add_argument("env", help="title of the desired environment (aws, arduino)")
  parser.add_argument("-c", "--cloud", help="sets src_filter for cloud folder", action="store_true")
  parser.add_argument("-hw", "--hardware", help="sets src_filter for hardware folder", action="store_true")
  args = parser.parse_args()

  env_config.read(ENV_INI_PATH)

  if args.env == envs[0]:
    env_config["common"]["src_filter"] = AWS_FILTER
    print(f"--> set the filter {AWS_FILTER} for aws")
  elif args.env == envs[1]:
    if args.cloud:
      env_config["common"]["src_filter"] = CLOUD_FILTER
      print(f"--> set the filter {CLOUD_FILTER} for arduino")
    elif args.hardware: 
      env_config["common"]["src_filter"] = HARDWARE_FILTER
      print(f"--> set the filter {HARDWARE_FILTER} for arduino")

  with open(ENV_INI_PATH, 'w') as f:
    env_config.write(f)

  print(f"--> the environment {args.env} has been set \n")


if __name__ == "__main__":
  print(f"\033[90m{__doc__}\033[0m", end="\n")
  checkFile()
  setEnvironment()


    

