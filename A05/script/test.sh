#!/bin/bash

test_counter=1
test_begin() {
    echo -e "\033[33mTEST $test_counter\033[0m"
    ((test_counter++))
}

# switch to the directory of the script
cd "$(dirname "$0")" && cd .. || exit
