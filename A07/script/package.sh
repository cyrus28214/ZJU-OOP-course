#!/bin/bash

cd "$(dirname "$0")" && cd .. || exit

PACKAGE_NAME=Assignment07+3230106230+LiuRenqin.zip

typst compile report/report.typ report/report.pdf --root .

cp report/report.pdf report.pdf

zip -r $PACKAGE_NAME README.md CMakeLists.txt script src test report report.pdf