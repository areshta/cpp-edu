#!/bin/bash

rm -f ./unformat.spp
rm -f i./unformat
cp unformat-example.src unformat.cpp
g++ -std=c++11 unformat.cpp -o unformat
echo "=== the example execution ==="
./unformat
echo -e "\n=== before formatting: ==="
cat ./unformat.cpp
#
clang-format -i unformat.cpp 
#
echo -e "\n=== after formatting: ==="
cat ./unformat.cpp

