// Author: David Darigan

#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Semaphore> mutexSem,std::shared_ptr<Semaphore> barrierSem, std::shared_ptr<int> threadCount){

  // We lock early to prevent writing issues
  mutexSem->Wait();     	
  std::cout << "first" << std::endl;
  
  (*threadCount)--;
  if((*threadCount) > 0) {
	  // We release inside of the loop so we avoid threadcount being manipulated while being read from
  	  mutexSem->Signal();
	  barrierSem->Wait();
  }
  mutexSem->Signal();
  barrierSem->Signal();
  
  mutexSem->Wait();
  std::cout << "second" << std::endl;
  mutexSem->Signal();
}

int main(void){
  std::shared_ptr<Semaphore> mutexSem;
  std::shared_ptr<Semaphore> barrierSem;
  std::shared_ptr<int> barrier;
  int threadCount = 5;
  mutexSem=std::make_shared<Semaphore>(1);
  barrierSem=std::make_shared<Semaphore>(0);
  /*!< An array of threads*/
  std::vector<std::thread> threadArray(threadCount);
  /*!< Pointer to barrier object*/
  barrier = std::make_shared<int>(threadCount);


  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,mutexSem,barrierSem,barrier);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  return 0;
}