#!/usr/bin/env python3

"""
Created: 11/12/21
by: Tim Schmid

convert .pem format to binary and upload to ESP32 flash
"""

import os
import shutil
import serial
import argparse
import esptool
from simple_term_menu import TerminalMenu
from OpenSSL import crypto
from OpenSSL import SSL

BASE_PATH = os.path.join(os.path.dirname(
    os.path.abspath(__file__)), os.pardir)


def args_pars():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "folder", help="define folder name which contains desired certificate files ")
    return parser.parse_args()


def convert_pem_to_der():
    print(BASE_PATH)


def create_term_menu(options: list()):
    term_menu = TerminalMenu(options)
    return term_menu.show()


if __name__ == "__main__":
    print(f"\033[90m{__doc__}\033[0m", end="\n")
    convert_pem_to_der()
