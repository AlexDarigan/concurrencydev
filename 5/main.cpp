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
  forks[philID].Wait();
  forks[(philID+1)%COUNT].Wait();
}

void put_forks(int philID){
  forks[philID].Signal();
  forks[(philID+1)%COUNT].Signal();  
}

void eat(int myID){
  int seconds=rand() % EATTIME + 1;
    std::cout << myID << " is chomping! "<<std::endl;
  sleep(seconds);  
}

void philosopher(int id/* other params here*/){
  while(true){
    think(id);
    get_forks(id);
    eat(id);
    put_forks(id);
  }//while  
}//philosopher


int main(void){
  srand (time(NULL)); // initialize random seed: 
  std::vector<std::thread> vt(COUNT);
  int id=0;
  for(std::thread& t: vt){
    t=std::thread(philosopher,id++/*,params*/);
  }
  /**< Join the philosopher threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  return 0;
}

/* main.c ends here */
