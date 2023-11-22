# Author	: David Darigan (C00263218)
# Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
# Git URL	: https://github.com/AlexDarigan/concurrencydev 

CFILES= saxpy.cpp
HFILES=
CC=g++
CFLAGS= -std=c++11 -pthread -fopenmp

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

SAXPY: saxpy.o
	$(CC) -o saxpy.out saxpy.o $(CFLAGS) $(DEBUGFLAGS)

MANDEL: mandelbroit.o
	$(CC) -o mandelbroit.out mandelbroit.o $(CFLAGS) $(DEBUGFLAGS)


DSAXPY: DEBUGFLAGS = -g -O0
DSAXPY: SAXPY

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
