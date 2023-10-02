CC=g++
CFLAGS= -std=c++11 -pthread

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

HELLO: helloThreads.o Semaphore.o
	$(CC) -o helloThreads helloThreads.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)
	
MUTUAL: mutualEx.o Semaphore.o
	$(CC) -o mutualEx mutualEx.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG

CLEAN:
	rm *.o
