#!/bin/bash
set -x

rm -f *.out
rm -f *.o
rm -f lib*.*

c++ -Wall -fPIC -c inputer.cpp
c++ -Wall -fPIC c summator.cpp

gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0   *.o

#c++ main.cpp libctest.a -o main


