CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: HarmSynth

HarmSynth : osc.o square.o saw.o sine.o jack_module.o main.o
	$(CC) -o $@ $(CFLAGS) osc.o square.o saw.o sine.o jack_module.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f HarmSynth
