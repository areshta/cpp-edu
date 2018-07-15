#!/bin/bash
set -x

rm -f *.out
rm -f *.o
rm -f lib*.*

c++ -c inputer.cpp
c++ -c summator.cpp
c++ main.cpp inputer.o summator.o -o main
