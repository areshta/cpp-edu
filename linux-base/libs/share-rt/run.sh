#!/bin/bash
set -x
rm -f ./main

c++ -rdynamic -o main main.cpp -ldl

./main

#c++ main.cpp libctest.a -o main


