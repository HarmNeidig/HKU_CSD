#! /bin/bash

g++ -c Dog_main.cpp
g++ -c Dog.cpp
g++ -o Dog Dog_main.cpp Dog.cpp

#rm Dog_main.o
#rm Dog.o
