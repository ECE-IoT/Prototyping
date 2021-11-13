#!/usr/bin/env python3

"""
Created: 11/12/21
by: Tim Schmid

convert .pem format to binary and upload to ESP32 flash
"""

import os
import esptool
from serial.tools import list_ports
from simple_term_menu import TerminalMenu
from OpenSSL import crypto
from OpenSSL import SSL

BASE_PATH = os.path.join(os.path.dirname(
    os.path.abspath(__file__)), os.pardir)
CERT_PATH = os.path.join(BASE_PATH, 'data')


def create_term_menu(options: list()):
    term_menu = TerminalMenu(options)
    return term_menu.show()


def convert_pem_to_der():
    files = os.listdir(CERT_PATH)
    assert files, "--> no files found, pleas add certification files to /data"

    for file in files:
        file_path = os.path.join(CERT_PATH, file)
        if file.endswith('.pem') or file.endswith('.crt'):
            with open(file_path, 'rb') as cert_file:
                cert_pem = crypto.load_certificate(
                    crypto.FILETYPE_PEM, cert_file.read())
                cert_der = crypto.dump_certificate(
                    crypto.FILETYPE_ASN1, cert_pem)
                if file.endswith('.pem'):
                    write(file_path, cert_der, 'device-key')
                else:
                    write(file_path, cert_der, 'root-key')
        elif file.endswith('.key'):
            with open(file_path, 'rb') as cert_file:
                cert_pem = crypto.load_privatekey(
                    crypto.FILETYPE_PEM, cert_file.read())
                cert_der = crypto.dump_privatekey(
                    crypto.FILETYPE_ASN1, cert_pem)
                write(file_path, cert_der, 'private-key')
        else:
            print(f"--> file {file} ALREADY to BINARY converted")


def write(file_path, cert_der, name):
    path = os.path.join(BASE_PATH, 'data', (name + '.der'))
    with open(path, 'wb') as cert_file_der:
        cert_file_der.write(cert_der)
        print(
            f"--> {file_path.split('/data')[1]} to BINARY {(name + '.der')} converted")
        os.remove(file_path)


if __name__ == "__main__":
    print(f"\033[90m{__doc__}\033[0m", end="\n")
    check = ["YES", "NO"]

    print('--> Do you want to convert .pem files?')
    if create_term_menu(check) == 0:
        print('--> Conversion started \n')
        convert_pem_to_der()
