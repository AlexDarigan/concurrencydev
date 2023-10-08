CC=g++
CFLAGS= -std=c++11 -pthread
TEST_LIB=/tests/libgtest.a

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

HELLO: helloThreads.o Semaphore.o
	$(CC) -o helloThreads helloThreads.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)
	
MUTUAL: mutualEx.o Semaphore.o
	$(CC) -o mutualEx mutualEx.o Semaphore.o $(CFLAGS) $(DEBUGFLAGS)

TEST: $(TEST_LIB)
	$(CC) -o example $(TEST_LIB) $(CFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG

CLEAN:
	rm *.o
