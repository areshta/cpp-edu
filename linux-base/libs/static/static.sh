#!/bin/bash
set -x

rm -f *.out
rm -f *.o
rm -f lib*.*

c++ -c inputer.cpp
c++ -c summator.cpp

ar -cvq libctest.a inputer.o summator.o

c++ main.cpp libctest.a -o main


