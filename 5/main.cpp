// Author	: David Darigan (C00263218)
// Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
// Git URL	: https://github.com/AlexDarigan/concurrencydev
/*! \file main.cpp
    \brief A Test Driver class about the Dining Philosopher's problem which indicates how to use mutual exclusion without starvation (lab 5)

*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include<unistd.h>

const int COUNT = 5;
const int THINKTIME=3;
const int EATTIME=5;
std::vector<Semaphore> forks(COUNT);


void think(int myID){
  int seconds=rand() % THINKTIME + 1;
  std::cout << myID << " is thinking! "<<std::endl;
  sleep(seconds);
}

void get_forks(int philID){
  if(philID == COUNT - 1) {
    forks[(philID+1)%COUNT].Wait();
    forks[philID].Wait();
  } else {
    forks[philID].Wait();
    forks[(philID+1)%COUNT].Wait();
  }
}

void put_forks(int philID){
  if(philID == COUNT - 1) {
    forks[(philID+1)%COUNT].Signal();
    forks[philID].Signal();
  } else {
    forks[philID].Signal();
    forks[(philID+1)%COUNT].Signal(); 
  }
}
void eat(int myID){
  int seconds=rand() % EATTIME + 1;
    std::cout << myID << " is chomping! "<<std::endl;
  sleep(seconds);  
}

void philosopher(int id, std::shared_ptr<Semaphore> forklifter){
  while(true){
    think(id);
    forklifter->Wait();
    get_forks(id);
    eat(id);
    put_forks(id);
    forklifter->Signal();
  }//while  
}//philosopher


int main(void){
  srand (time(NULL)); // initialize random seed: 
  std::shared_ptr<Semaphore> forklifter = std::make_shared<Semaphore>(4);
  std::vector<std::thread> vt(COUNT);
  for(Semaphore& s: forks) {
  // Semaphores need to be at 1 otherwise no one will ever even get a fork
    s.Signal();
  }
  int id=0;
  for(std::thread& t: vt){
    t=std::thread(philosopher,id++, forklifter);
  }
  /**< Join the philosopher threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  return 0;
}

/* main.c ends here */
