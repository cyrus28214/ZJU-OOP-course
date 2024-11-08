#!/bin/bash

SCRIPT_DIR=$(dirname "$(realpath "$0")")
PROGRAM_NAME=$SCRIPT_DIR/build/Adventure

ask_run() {
    read -p "编译完成。是否要运行程序？(y/N): " choice
    if [[ "$choice" == "y" || "$choice" == "Y" ]]; then
        $PROGRAM_NAME
    fi
}

cd "$SCRIPT_DIR" && \
mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build . && \
    ask_run
