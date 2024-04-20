#!/bin/bash

# Compile the cpp file
g++ -std=c++11 -o main main.cpp

A1Path="test-files/A1.txt"
b1Path="test-files/b1.txt"

# Run the compiled file
./main $A1Path $b1Path