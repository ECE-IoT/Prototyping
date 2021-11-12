#!/usr/bin/env python3

"""
Created: 11/12/21
by: Tim Schmid

automatically update the sub scripts into the code folder
"""

import os
import shutil
import itertools

BASE_PATH = os.path.join(os.path.dirname(
    os.path.abspath(__file__)), os.pardir)
CODE_PATH = os.path.join(BASE_PATH, 'code')
SUB_SCRIPTS = os.path.join(BASE_PATH, 'scripts', 'sub-scripts')


def get_code_script_path():
    folders = list()
    for f, subfolders, filenames in os.walk(CODE_PATH):
        if "scripts" in f.split('../')[1]:
            folders.append(f)
    return folders


def update_scripts():
    script_folder = get_code_script_path()
    print(script_folder)
    sub_scripts = os.listdir(SUB_SCRIPTS)
    sub_scripts_folders = list()
    for sbs in sub_scripts:
        sub_scripts_folders.append(os.path.join(SUB_SCRIPTS, sbs))

    for scripts in script_folder:
        for sbs in sub_scripts_folders:
            shutil.copy(sbs, scripts)


if __name__ == "__main__":
    update_scripts()
