CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : sine.o osc.o fm_synth.o jack_module.o main.o
	$(CC) -o $@ $(CFLAGS) sine.o osc.o fm_synth.o jack_module.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
