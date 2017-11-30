#!/bin/bash
g++ -std=c++14 -pthread *.cpp
./a.out
rm -f ./a.out
