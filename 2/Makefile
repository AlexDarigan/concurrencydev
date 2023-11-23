# Author: Joseph Kehoe
# Edited by: David Darigan (C00263218)
# Last Modified: Nov 23 2023# Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
# Git URL	: https://github.com/AlexDarigan/concurrencydev 

CC=g++
CFLAGS= -std=c++11 -pthread -Wall
RENDEZ_FILES=rendezvous.o Semaphore.o Semaphore.h

# Inform make that .o files require .cpp files of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

# Our main build rule
RELEASE: $(RENDEZ_FILES)
	$(CC) -o rendezvous $(RENDEZ_FILES) $(CFLAGS) $(DEBUGFLAGS)

# Set Debug Flags & Build Debug Build
DEBUG: DEBUGFLAGS = -DDEBUG

# Call RELEASE rule with the Debug Flags as the second step of the debug rule
DEBUG: RELEASE

# Remove used .o files that are no longer needed
CLEAN:
	rm *.o
