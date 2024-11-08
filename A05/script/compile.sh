#!/bin/bash

# switch to the directory of the script
cd "$(dirname "$0")" || exit

mkdir -p ../build && \
    cd ../build && \
    cmake .. && \
    cmake --build .