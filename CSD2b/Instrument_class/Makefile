CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z

all: example

example : Instrument_class.o Instrument_main.o
	$(CC) -o $@ $(CFLAGS) Instrument_class.o Instrument_main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
