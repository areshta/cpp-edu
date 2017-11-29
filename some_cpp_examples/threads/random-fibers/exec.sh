#!/bin/bash
rm -f ./a.out
g++ -std=c++14 -pthread *.cpp
./a.out
rm -f ./a.out
