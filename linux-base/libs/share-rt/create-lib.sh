#!/bin/bash
set -x

rm -f *.out
rm -f ./lib/*.o
rm -f ./lib/lib*.*
rm *.so


c++ -Wall -fPIC -c inputer.cpp -o ./lib/inputer.o
c++ -Wall -fPIC -c summator.cpp -o ./lib/summator.o

pushd ./lib
gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0   *.o

ln -s ./libctest.so.1.0 ./libctest.so.1 
ln -s ./libctest.so.1 ./libctest.so

popd

#c++ main.cpp libctest.a -o main


