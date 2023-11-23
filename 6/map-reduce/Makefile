# Author: Joseph Kehoe
# Edited by: David Darigan (C00263218)
# Last Modified: Nov 23 2023
# Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
# Git URL	: https://github.com/AlexDarigan/concurrencydev 

CPPFILES= reduction.cpp
HFILES=
CC=g++
CFLAGS= -std=c++11  -fopenmp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) -lgomp  $(DEBUGFLAGS)

REDUCE: reduction.o
	$(CC) -o reduce.out reduction.o $(CFLAGS) $(DEBUGFLAGS)


DREDUCE: DEBUGFLAGS = -g -O0
DREDUCE: REDUCE

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
