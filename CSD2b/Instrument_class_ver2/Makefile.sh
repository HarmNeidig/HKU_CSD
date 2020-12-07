#! /bin/bash

gcc -c Instrument_main.cpp
gcc -c Instrument.cpp
gcc -o Instrument Instrument_main.cpp Instrument.cpp

rm Instrument_main.o
rm Instrument.o
