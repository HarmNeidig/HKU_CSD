#! /bin/bash

g++ -c Hello_world.cpp
g++ -c world.cpp
g++ -o Hello_world Hello_world.cpp world.cpp

rm Hello_world.o
rm world.o
