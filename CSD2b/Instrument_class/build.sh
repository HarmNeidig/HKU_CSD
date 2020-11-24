gcc -c Instrument.cpp
gcc -c Instrument_class.cpp
gcc -o Instrument Instrument.cpp Instrument_class.cpp

rm Instrument.o Instrument_class.o
