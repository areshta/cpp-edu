#!/bin/bash
set -x

rm -f *.out
rm -f *.o
rm -f lib*.*
rm *.so


c++ -Wall -fPIC -c inputer.cpp
c++ -Wall -fPIC -c summator.cpp

gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0   *.o

ln -s ./libctest.so.1.0 ./libctest.so.1 
ln -s ./libctest.so.1 ./libctest.so

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
g++ -Wall  -L./ main.cpp -lctest -o main 

./main

#c++ main.cpp libctest.a -o main


