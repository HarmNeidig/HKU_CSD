CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z

all: SjekDraaier

SjekDraaier : Sjek.o Sjek_main.o
	$(CC) -o $@ $(CFLAGS) Sjek.o Sjek_main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
