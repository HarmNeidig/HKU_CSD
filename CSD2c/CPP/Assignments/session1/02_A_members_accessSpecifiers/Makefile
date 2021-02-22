CC = g++ -g

all: instrument

instrument: InstrDerived.o Instrument.o main.o
	$(CC) -o $@ InstrDerived.o Instrument.o main.o

.cpp.o:
	$(CC) -c $<

clean:
	rm -f *.o
	rm -f instrument
