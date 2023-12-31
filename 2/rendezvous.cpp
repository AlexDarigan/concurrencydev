// Author: Joseph Kehoe
// Edited by: David Darigan (C00263218)
// Last Modified: Nov 23 2023
// Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
// Git URL	: https://github.com/AlexDarigan/concurrencydev
/*! \file rendezvous.cpp
    \brief A Test Driver class for thread management through a rendevouz

*/

#include "Semaphore.h"
#include <thread>
#include <vector>
#include <iostream>
#include <string>

// Assertions used in testing
template <typename A, typename B>
void isEqual(A expected, B actual, std::string context) {
        bool result = (expected == actual);
        if(result) {
            std::cout << "SUCCESS on context: " + context << std::endl;
        } else {
            std::cout << "FAIL on context: " + context << " (" << "EXPECT: " << expected << ", " << "ACTUAL: " << actual << ")" << std::endl;
        }
}

bool set_once = false;
int arrived = 0;
int left = 0;

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Semaphore> mutexSem,std::shared_ptr<Semaphore> barrierSem, std::shared_ptr<int> threadCount){

    std::cout << "first " << std::endl;
    //put barrier code here
    mutexSem->Wait();
    ++arrived;
    --(*threadCount);
    if((*threadCount) == 0) {
        barrierSem->Signal();
    }
    mutexSem->Signal();
    barrierSem->Wait();
    mutexSem->Wait();
    ++left;
    std::cout << arrived;
    if(left < arrived) {
      barrierSem->Signal();
    } else {
      // Clearing for the next run
      arrived = 0;
      left = 0;
    }
    mutexSem->Signal();
    std::cout << "second " << std::endl;
}



void testCounts() {
  const int mutexCount = 1;
  const int barrierCount = 0;
  int threadCount = 5;

  std::shared_ptr<Semaphore> mutexSem;
  std::shared_ptr<Semaphore> barrierSem;
  std::shared_ptr<int> barrier;
  mutexSem=std::make_shared<Semaphore>(mutexCount);
  barrierSem=std::make_shared<Semaphore>(barrierCount);
  barrier = std::make_shared<int>(threadCount);
  std::vector<std::thread> threadArray(threadCount);

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,mutexSem,barrierSem,barrier);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }

  isEqual<int,int>(mutexCount, mutexSem->getCount(), "Mutex Sem count reverted to original");
  isEqual<int,int>(barrierCount, barrierSem->getCount(), "Barrier sem count reverted to original");
  isEqual<int,int>(0, *barrier, "Thread count for barrier reduced to 0");
}

int main(void){
  // Manual Test
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

  // Other tests
  testCounts();
  
  return 0;
}