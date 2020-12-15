CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z

all: example

example : Bass_subclass.o Guitar_subclass.o Instrument_class.o main.o
	$(CC) -o $@ $(CFLAGS) Bass_subclass.o Guitar_subclass.o Instrument_class.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
