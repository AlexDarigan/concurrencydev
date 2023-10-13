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
  if(philID == COUNT) {
    forks[0].Wait();
    forks[COUNT - 1].Wait();
  } else {
    forks[philID].Wait();
    forks[(philID+1)%COUNT].Wait();
  }
}

void put_forks(int philID){
  if(philID == COUNT) {
    forks[0].Signal();
    forks[COUNT - 1].Signal();
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
   // forklifter->Wait();
    get_forks(id);
    eat(id);
    put_forks(id);
   // forklifter->Signal();
  }//while  
}//philosopher


int main(void){
  srand (time(NULL)); // initialize random seed: 
  // X PHILOSOPHERS, EACH WANTS 2 FORKS, THERE IS X FORKS
  std::shared_ptr<Semaphore> forklifter = std::make_shared<Semaphore>((COUNT / 2) - 2);
  std::vector<std::thread> vt(COUNT);
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
