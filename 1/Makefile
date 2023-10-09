# Author: David Darigan (C00263218)

CC=g++
CFLAGS=-std=c++11 -pthread
HELLO_FILES=helloThreads.o Semaphore.o
MUTUAL_FILES=mutualEx.o Semaphore.o

# Inform make that .o files require .cpp files of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

RELEASE: $(HELLO_FILES) $(MUTUAL_FILES)
	$(CC) -o helloThreads $(HELLO_FILES) $(CFLAGS) $(DEBUGFLAGS)
	$(CC) -o mutualEx $(MUTUAL_FILES) $(CFLAGS) $(DEBUGFLAGS)

# Set Debug Flags & Build Debug Build
DEBUG: DEBUGFLAGS = -DDEBUG

# Remove used .o files that are no longer needed
CLEAN:
	rm *.o
