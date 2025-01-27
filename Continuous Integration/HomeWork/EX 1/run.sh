#!/bin/bash

clear
if [ -d "Build" ]; then
  rm -rf Build
fi

mkdir Build && cd Build

c++ -c ../Lib/fizzbuzz.cpp -o lib.o
c++ -c ../Test/test.cpp -o test.o -I../Lib
c++ -o index ../Src/index.cpp lib.o

./index