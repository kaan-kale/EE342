#!/bin/bash

# Compile the cpp file
g++ -std=c++11 -o main main.cpp

# Loop over the numbers from 1 to 10
for test_idx in {1..12}
do
    echo "Test Case ${test_idx}"

  A1Path="test-files/A${test_idx}.txt"
  b1Path="test-files/b${test_idx}.txt"

  # Run the compiled file
  ./main $A1Path $b1Path
done