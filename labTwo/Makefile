#Joseph Kehoe 13/9/2017
#First simple Makefile
#Used to contain commands to compile projects
#Equivalent(?) to a project file in VStudio -- only better!
#See http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ for info.


CC=g++
CFLAGS= -std=c++11 -pthread

SIMPLE: rendezvous.cpp Semaphore.cpp Semaphore.h
	g++ -std=c++11 -pthread rendezvous.cpp Semaphore.cpp Semaphore.h


CLEAN:
	rm *.o
