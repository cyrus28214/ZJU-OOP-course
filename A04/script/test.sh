#!/bin/bash

test_counter=1
test_begin() {
    echo -e "\033[33mTEST $test_counter\033[0m"
    ((test_counter++))
}

# switch to the directory of the script
cd "$(dirname "$0")" && cd .. || exit

diary_2024_10_27="Today the \"learning in ZJU\" platform crashed. We don't need to take the exam as planned."
diary_2024_10_28="Today I have an OOP class."
diary_2024_10_29="Nothing happened."


mkdir -p test
cp -r bin/* test/
cd test

test_begin
echo "Add diary 2024-10-27"
echo $diary_2024_10_27 | ./pdadd 2024-10-27

test_begin
echo "Add diary 2024-10-28"
echo $diary_2024_10_28 | ./pdadd 2024-10-28

test_begin
echo "List all (verbose)"
./pdlist -v

test_begin
echo "Show diary 2024-10-27"
./pdshow 2024-10-27

test_begin
echo "Add diary 2024-10-29"
echo $diary_2024_10_29 | ./pdadd 2024-10-29

test_begin
echo "List between 2024-10-28 and 2024-10-29"
./pdlist 2024-10-28 2024-10-29

test_begin
echo "Remove 2024-10-28"
./pdremove 2024-10-28

test_begin
echo "List all"
./pdlist