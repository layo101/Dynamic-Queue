all: test

test: QT1.o queue.o
	g++ -Wall -o QT1 QT1.o queue.o

QT1.o:
	g++ -Wall -o QT1.o -c QT1.cpp

queue.o: queue.cpp queue.h
	g++ -Wall -o queue.o -c queue.cpp

clean:
	rm -f test *.o

