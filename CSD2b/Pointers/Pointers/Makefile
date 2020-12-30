CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z

all: example

example : square.o main.o
	$(CC) -o $@ $(CFLAGS) square.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
