// Author: David Darigan

#include "Barrier.h"

/*! \class Barrier
    \brief An Implementation of a barrier Using Semaphores 

   Uses C++11 features such as mutex and condition variables to implement a barrier using Semaphores with N number threads

*/
/*! Barrier constructor*/
Barrier::Barrier(){

  this->count = 0;
  threadNum = 0;
  condition = false;
<<<<<<< Updated upstream
  mutex = std::make_shared<Semaphore>(1);
  entry = std::make_shared<Semaphore>(0);
  exit = std::make_shared<Semaphore>(1);

=======
  mutex=std::make_shared<Semaphore>(1);
  //std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  barrier1=std::make_shared<Semaphore>(0);
  //std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  //std::shared_ptr<Semaphore> barrier2(new Semaphore(1));
  entry=std::make_shared<Semaphore>(0);
  exit=std::make_shared<Semaphore>(1);
>>>>>>> Stashed changes
}

/*! Barrier with parameter constructor*/
Barrier::Barrier(int count){

  this->count = count;
  threadNum = 0;
  condition = false;
<<<<<<< Updated upstream
  mutex = std::make_shared<Semaphore>(1);
  entry = std::make_shared<Semaphore>(0);
  exit = std::make_shared<Semaphore>(1);
=======
  mutex=std::make_shared<Semaphore>(1);
  entry=std::make_shared<Semaphore>(0);
  exit=std::make_shared<Semaphore>(1);
  //std::shared_ptr<Semaphore> barrier1(new Semaphore(0));
  // std::shared_ptr<Semaphore> barrier2(new Semaphore(1));
>>>>>>> Stashed changes
}
/*! Barrier deconstructor*/
Barrier::~Barrier(){

}


/*! waits for all the threads before starting second half of code*/ 
void Barrier::waitForAll(){

  mutex->Wait();
  threadNum++;

<<<<<<< Updated upstream
  if(threadNum == count){
    exit->Wait(); // 0
    entry->Signal(); // 1
  }
  mutex->Signal();
  entry->Wait();
  entry->Signal();
  mutex->Wait();
  threadNum--;
  if(threadNum == 0) {
    entry->Wait(); // -count
    exit->Signal(); // 1
  }
  mutex->Signal();
  exit->Wait();
  exit->Signal();
=======
  if(threadNum == count) {
    entry->Signal();
    threadNum = 0;
  }
  mutex->Signal(); //
  entry->Wait();
  entry->Signal();
>>>>>>> Stashed changes
}


/// @cond DO_NOT_DOCUMENT
  // readonly test-use methods

int Barrier::getCount(){

  return this->count;
}

int Barrier::getMutexCount() {
  return mutex->getCount();
}

int Barrier::getEntryCount() {
  return entry->getCount();
}

int Barrier::getExitCount() {
  return exit->getCount();
}

/// @endcond
