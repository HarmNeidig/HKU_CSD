CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE= synthesizer.o melodyGen.o osc.o square.o saw.o sine.o jack_module.o main.o

all: HarmSynth

HarmSynth : $(SOURCE)
	$(CC) -o $@ $(CFLAGS) $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f HarmSynth
