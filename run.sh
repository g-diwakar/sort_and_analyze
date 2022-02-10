#!/bin/bash
rm -rf build 
mkdir build
cd build
g++ -c ../src/*.cpp
g++ ./*.o -o main -lsfml-graphics -lsfml-system -lsfml-window
./main



