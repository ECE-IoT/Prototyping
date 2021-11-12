#!/usr/bin/env python3

"""
Created: 10/20/21
by: Tim Schmid

automatically update the docs/ in order to create suitable mkdocs on github-pages
"""

import os
from shutil import copytree, ignore_patterns, rmtree
import yaml

BASE_PATH = os.path.join(os.path.dirname(
    os.path.abspath(__file__)), os.pardir)
CONF_PATH = os.path.join(BASE_PATH, 'config')
DOC_PATH = os.path.join(CONF_PATH, 'docs')
SCRIPT_PATH = os.path.join(BASE_PATH, 'config', 'docs', 'docs-path.yml')
MKDOCS_PATH = os.path.join(BASE_PATH, 'docs', 'code')
SRC_DOCS_PATH = os.path.join(BASE_PATH, 'code')


def rm_empty_dir():
    for folders, subfolders, filenames in os.walk(MKDOCS_PATH):
        if not subfolders and not filenames:
            os.rmdir(folders)


def add_dir_to_docs():
    yaml_file_paths = []
    with open(SCRIPT_PATH, 'w') as yaml_file:
        for folders, subfolders, filenames in os.walk(MKDOCS_PATH):
            sub_paths = folders.split(os.path.join(os.pardir, "docs"))[1]
            if filenames:
                for f_name in filenames:
                    if f_name.endswith('{}'.format('.md')):
                        file_paths = sub_paths.replace(
                            '\\', '/').lstrip("/") + '/' + f_name
                        yaml_file_paths.append({f_name: file_paths})
        yaml.dump(yaml_file_paths, yaml_file)


if __name__ == "__main__":
    print(f"\033[90m{__doc__}\033[0m", end="\n")
    print("--> copy all essential files into /docs")

    if not os.path.exists(CONF_PATH) and not os.path.exists(DOC_PATH):
        os.mkdir(CONF_PATH, 0o755)
        os.mkdir(os.path.join(DOC_PATH), 0o755)
    elif os.path.exists(CONF_PATH) and not os.path.exists(DOC_PATH):
        os.mkdir(os.path.join(CONF_PATH, 'docs'))

    if os.path.exists(MKDOCS_PATH):
        rmtree(MKDOCS_PATH)
        print("--> remove old /docs revision first")

    try:
        print("--> copying file tree")
        copytree(SRC_DOCS_PATH, MKDOCS_PATH, ignore=ignore_patterns(
            '*.cpp', '*.hpp', '*.c', '*.h', '*.json', '*.DS_Store'))
        print("--> remove empty directories")
        rm_empty_dir()
        print("--> done \n")
    except:
        print("!! --> an error occured \n")

    add_dir_to_docs()
