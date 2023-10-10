# Author	: David Darigan (C00263218)
# Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
# Git URL	: https://github.com/AlexDarigan/concurrencydev 

CC=g++
CFLAGS=-std=c++11 -pthread -Wall
HELLO_FILES=helloThreads.o Semaphore.o
MUTUAL_FILES=mutualEx.o Semaphore.o

# Inform make that .o files require .cpp files of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# We are compiling two seperate projects here, hence two seperate set of files
RELEASE: $(HELLO_FILES) $(MUTUAL_FILES)
	$(CC) -o helloThreads $(HELLO_FILES) $(CFLAGS) $(DEBUGFLAGS)
	$(CC) -o mutualEx $(MUTUAL_FILES) $(CFLAGS) $(DEBUGFLAGS)

# Set Debug Flags as the first step of the debug rule
DEBUG: DEBUGFLAGS = -DDEBUG

# Call RELEASE rule with the Debug Flags as the second step of the debug rule
DEBUG: RELEASE

# Remove used .o files that are no longer needed
CLEAN:
	rm *.o
