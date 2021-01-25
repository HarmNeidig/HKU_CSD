CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: synth_mono

synth_mono : sine.o saw.o square.o osc.o synth.o generator.o jack_module.o main.o
	$(CC) -o $@ $(CFLAGS) sine.o saw.o square.o osc.o synth.o generator.o jack_module.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f synth_mono
