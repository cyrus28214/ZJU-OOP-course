#!/bin/bash

cd "$(dirname "$0")" && cd .. || exit

PACKAGE_NAME=Assignment06+3230106230+LiuRenqin.zip

zip -r $PACKAGE_NAME README.md CMakeLists.txt script src test